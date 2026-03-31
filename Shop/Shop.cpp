#include "Shop.h"
#include "ShopUI.h"
#include "ShopLogic.h"
#include "../Player/Player/Player.h"
#include "../System/Windows.h"

using namespace std;

// 상점 메뉴 
void Shop::showShopMenu(Player* player)
{
    while (true)
    {
        displayShop(player->getGold());

        int menuchoice;
        cin >> menuchoice;

        if (menuchoice == 0) break;

        switch (menuchoice)
        {
        // 메인 메뉴의 '무기 상점' 진입
        case 1:
            {
                displayShopMenu("무기");
                int subChoice;
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    {
                        // 1. 플레이어의 직업 이름 가져오기 (예: "Warrior", "Mage")
                        string playerJob = player->getJobName();
                        system("cls");
                        // case 1: 무기 구매 목록 출력 부분
                        displayShopHead();
                        cout << "|    [ 번호 ]    이름                     가격                   공격력        |" << '\n';
                        cout << "+==============================================================================+" <<
                            '\n';

                        int index = 1;
                        map<int, int> indexToID;

                        for (auto& pair : weaponDB)
                        {
                            auto& item = pair.second;
                            if (!item.base.canBuy) continue;

                            string itemTag = item.base.jobTag;
                            if (itemTag != "Common" && itemTag != playerJob) continue;

                            // UI 조립 및 출력
                            indexToID[index] = pair.first;

                            cout << "|    [  " << left << setw(3) << index << "]     "
                                << left << setw(25) << item.base.name
                                << right << setw(6) << item.base.price << "G           "
                                << "공격력 +" << setw(3) << item.attack << "        |" << '\n';
                            index++;
                        }

                        if (index == 1)
                        {
                            cout << "|              현재 구매 가능한 무기가 없습니다.                               |" << '\n';
                        }
                        cout << "+==============================================================================+" <<
                            '\n';
                        cout << "|   선택 >>                                                                    |" <<
                            '\n';
                        cout << "+==============================================================================+" <<
                            '\n';
                        Windows::SetCursorPos(13, 19);

                        int choice;
                        cin >> choice;

                        // 무기 상세 정보 및 최종 확인 (기존 로직 유지)
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            auto& selectedWeapon = weaponDB[itemId];

                            displayBuyDetail(selectedWeapon.base, selectedWeapon.attack, "공격력");

                            int confirm;
                            cin >> confirm;

                            if (confirm == 1)
                            {
                                if (player->getGold() >= selectedWeapon.base.price)
                                {
                                    player->subGold(selectedWeapon.base.price);
                                    if (player->getInventory() != nullptr)
                                    {
                                        player->getInventory()->addItem(itemId, 1);
                                    }
                                    cout << "\n[!] " << selectedWeapon.base.name << " 1개를 구매했습니다!\n";
                                    cout << "현재 남은 금화: " << player->getGold() << "G\n";
                                    _getch();
                                }
                                else
                                {
                                    displayNoGold();
                                }
                            }
                            else
                            {
                                displayBuyCancel();
                            }
                        }
                        else
                        {
                            displayNoNumber();
                        }
                        break;
                    }

                case 2:
                    {
                        // 무기 판매 시스템
                        cout << "\n\n=== 소지 무기 목록 ===\n";
                        int index = 1;
                        map<int, int> indexToID;

                        // 소지한 무기 목록 출력 ( 이름만 출력)
                        auto& items = player->getInventory()->getItems();
                        for (auto& pair : items)
                        {
                            int itemId = pair.first;
                            if (weaponDB.count(itemId))
                            {
                                cout << "[" << index << "] " << weaponDB[itemId].base.name
                                    << " (보유: " << pair.second << "개) \n";
                                indexToID[index] = itemId;
                                index++;
                            }
                        }

                        if (index == 1)
                        {
                            cout << "판매할 무기가 없습니다.\n";
                            break;
                        }

                        cout << "----------------------\n";
                        cout << "판매할 무기 번호 선택 >> ";
                        int choice;
                        cin >> choice;

                        // 2. 무기 상세 정보 및 판매 확인
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            int qty = items.at(itemId);
                            displaySellDetail(weaponDB[itemId].base, weaponDB[itemId].attack, "공격력", qty);

                            int confirm;
                            cin >> confirm;

                            if (confirm == 1)
                            {
                                sellItem(itemId, ItemType::Weapon, qty, player);
                            }
                            else
                            {
                                displaySellCancel();
                            }
                        }
                        else
                        {
                            displayNoNumber();
                        }
                        break;
                    }
                default:
                    displayNoNumber();
                    break;
                }
                break; // 무기의 케이스 종료 ->  상점메뉴로 되돌아감
            }
        case 2:
            {
                // 메인 메뉴의 '방어구 상점' 진입
                displayShopMenu("방어구");

                int subChoice;
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    {
                        system("cls");
                        // case 2: 방어구 구매 목록 출력 부분
                        displayShopHead();
                        cout << "|    [ 번호 ]    이름                     가격                   방어력        |" << '\n';
                        cout << "+==============================================================================+" <<
                            '\n';

                        int index = 1;
                        map<int, int> indexToID;

                        for (auto& pair : armorDB)
                        {
                            auto& item = pair.second;
                            if (!item.base.canBuy) continue;

                            string itemTag = item.base.jobTag;
                            if (itemTag != "Common") continue;

                            // UI 조립 및 출력
                            indexToID[index] = pair.first;

                            cout << "|    [  " << left << setw(3) << index << "]     "
                                << left << setw(25) << item.base.name
                                << right << setw(6) << item.base.price << "G           "
                                << "방어력 +" << setw(3) << item.defense << "        |" << '\n';
                            index++;
                        }

                        if (index == 1)
                        {
                            cout << "|              현재 구매 가능한 방어구가 없습니다.                             |" << '\n';
                        }
                        cout << "+==============================================================================+" <<
                            '\n';
                        cout << "|   선택 >>                                                                    |" <<
                            '\n';
                        cout << "+==============================================================================+" <<
                            '\n';
                        Windows::SetCursorPos(13, 18);

                        int choice;
                        cin >> choice;

                        // 방어구 상세 정보 확인 및 최종 승인 절차
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            auto& selectedArmor = armorDB[itemId];

                            displayBuyDetail(armorDB[itemId].base, armorDB[itemId].defense, "방어력");

                            int confirm;
                            cin >> confirm;

                            if (confirm == 1)
                            {
                                if (confirm == 1)
                                {
                                    // 돈 확인 및 차감 (함수 호출 방식)
                                    if (player->getGold() >= selectedArmor.base.price)
                                    {
                                        player->subGold(selectedArmor.base.price); // subGold(값)

                                        // 인벤토리에 추가 (addItem 사용)
                                        if (player->getInventory() != nullptr)
                                        {
                                            player->getInventory()->addItem(itemId, 1);
                                        }

                                        cout << "\n[!] " << selectedArmor.base.name << " 1개를 구매했습니다!\n";
                                        cout << "현재 남은 금화: " << player->getGold() << "G\n";
                                        _getch();
                                    }
                                    else
                                    {
                                        displayNoGold();
                                    }
                                }
                            }
                            else
                            {
                                displayBuyCancel();
                            }
                        }
                        else
                        {
                            displayNoNumber();
                        }
                        break;
                    }

                case 2:
                    {
                        // 방어구 판매 시스템
                        cout << "\n\n=== 소지 방어구 목록 ===\n";
                        int index = 1;
                        map<int, int> indexToID;

                        if (player->getInventory() == nullptr)
                        {
                            cout << "인벤토리 정보를 불러올 수 없습니다.\n";
                            break;
                        }

                        // 2. 인벤토리의 모든 아이템 중 '방어구'만 출력
                        auto& items = player->getInventory()->getItems();
                        for (auto& pair : items)
                        {
                            int itemId = pair.first;
                            int count = pair.second;

                            // armorDB에 해당 ID가 있다면 방어구입니다.
                            if (armorDB.count(itemId) && count > 0)
                            {
                                cout << "[" << index << "] " << armorDB[itemId].base.name
                                    << " (보유: " << count << "개)\n";
                                indexToID[index] = itemId;
                                index++;
                            }
                        }

                        if (index == 1)
                        {
                            cout << "판매할 방어구가 없습니다.\n";
                            break;
                        }

                        cout << "----------------------\n";
                        cout << "판매할 방어구 번호 선택 >> ";
                        int choice;
                        cin >> choice;

                        // 방어구 상세 정보 확인 및 최종 승인 절차
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            auto& selectedArmor = armorDB[itemId];
                            int currentCount = items.at(itemId);

                            displaySellDetail(selectedArmor.base, selectedArmor.defense, "방어력", currentCount);

                            int confirm;
                            cin >> confirm;

                            if (confirm == 1)
                            {
                                sellItem(itemId, ItemType::Armor, 1, player);
                            }
                            else
                            {
                                displaySellCancel();
                            }
                        }
                        else
                        {
                            displayNoNumber();
                        }
                        break;
                    }
                default:
                    displayNoNumber();
                    break;
                }
                break;
            }
        // 소모품 상점
        case 3:
            {
                displayShopHead();
                cout << "|                                                                              |" << '\n';
                cout << "|    " << right << setw(39) << "소모품 상점" << "                                   |" << '\n';
                cout << "|                                                                              |" << '\n';
                cout << "+==============================================================================+" << '\n';
                cout << "|    [ 번호 ]    이름                     가격                   효과          |" << '\n';
                cout << "+==============================================================================+" << '\n';
                int index = 1;
                map<int, int> indexToID;

                for (auto& pair : consumableDB)
                {
                    if (!pair.second.base.canBuy) continue;
                    auto& item = pair.second;

                    indexToID[index] = pair.first;

                    string effect = "HP +" + to_string(static_cast<int>(item.hpRatio * 100.0f)) + "%";
                    cout << "|    [  " << left << setw(2) << index << "]     "
                        << left << setw(25) << item.base.name
                        << right << setw(6) << item.base.price << "G                "
                        << left << setw(10) << effect << "     |" << '\n';
                    index++;
                }

                if (index == 1)
                {
                    cout << "|              현재 구매 가능한 소모품이 없습니다.                             |" << '\n';
                }
                cout << "+==============================================================================+" << '\n';
                cout << "|   선택 >>                                                                    |" << '\n';
                cout << "+==============================================================================+" << '\n';
                Windows::SetCursorPos(13, 20);
                
                int choiceIndex;
                cin >> choiceIndex;

                // 소모품의 상세 정보 출력 및 수량 입력
                if (indexToID.count(choiceIndex))
                {
                    int itemId = indexToID[choiceIndex];
                    auto& selectedItem = consumableDB[itemId];

                    cout << "\n--- [ " << selectedItem.base.name << " ] ---\n";
                    cout << "가격   : " << selectedItem.base.price << "G\n";
                    cout << "회복량 : " << selectedItem.hpRatio << "% HP\n";
                    cout << "------------------------\n";

                    cout << "구매할 수량을 입력하세요 >> ";
                    int qty;
                    cin >> qty;

                    if (qty <= 0)
                    {
                        cout << "1개 이상의 수량을 입력해야 합니다.\n";
                        break;
                    }

                    // 총 가격을 계산하고 입력한 갯수도 반환함
                    int totalPrice = selectedItem.base.price * qty;

                    cout << "총 가격: " << totalPrice << "G (" << qty << "개)\n";
                    cout << "구매하시겠습니까? (1.예 / 2.아니오) >> ";

                    int confirm;
                    cin >> confirm;

                    if (confirm == 1)
                    {
                        buyItem(itemId, ItemType::Consumable, qty, player);
                    }
                    else
                    {
                        displayBuyCancel();
                    }
                }
                else
                {
                    displayNoNumber();
                }
                break;
            }
        }
    }
}

#include "Shop.h"
#include "ShopUI.h"
#include "ShopLogic.h"
#include "../Player/Player/Player.h"

// 상점 메뉴 
void Shop::showShopMenu(Player* player)
{
    while (true)
    {
        displayShop(player->getGold());
        cout << "선택 >> ";

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
                std::cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    {
                        // 무기 구매 시스템
                        std::cout << "\n=== 무기 구매 목록 ===\n";
                        int index = 1;
                        std::map<int, int> indexToID;

                        // 무기 목록 출력 (이름만 출력)
                        for (auto& pair : weaponDB)
                        {
                            if (!pair.second.base.canBuy) continue;
                            std::cout << "[" << index << "] " << pair.second.base.name << "\n";
                            indexToID[index] = pair.first;
                            index++;
                        }

                        std::cout << "----------------------\n";
                        std::cout << "확인할 무기 번호 선택 >> ";
                        int choice;
                        std::cin >> choice;

                        // 무기 상세 정보 및 최종 확인
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            auto& selectedWeapon = weaponDB[itemId];

                            displayBuyDetail(selectedWeapon.base, selectedWeapon.attack, "공격력");

                            int confirm;
                            std::cin >> confirm;


                            if (confirm == 1)
                            {
                                if (player->getGold() >= selectedWeapon.base.price)
                                {
                                    player->subGold(selectedWeapon.base.price);
                                    if (player->getInventory() != nullptr)
                                    {
                                        player->getInventory()->addItem(itemId, 1);
                                    }
                                    std::cout << "\n[!] " << selectedWeapon.base.name << " 1개를 구매했습니다!\n";
                                    std::cout << "현재 남은 금화: " << player->getGold() << "G\n";
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
                        std::cout << "\n=== 소지 무기 목록 ===\n";
                        int index = 1;
                        std::map<int, int> indexToID;

                        // 소지한 무기 목록 출력 ( 이름만 출력)
                        auto& items = player->getInventory()->getItems();
                        for (auto& pair : items)
                        {
                            int itemId = pair.first;
                            if (weaponDB.count(itemId))
                            {
                                std::cout << "[" << index << "] " << weaponDB[itemId].base.name
                                    << " (보유: " << pair.second << "개)\n";
                                indexToID[index] = itemId;
                                index++;
                            }
                        }

                        if (index == 1)
                        {
                            std::cout << "판매할 무기가 없습니다.\n";
                            break;
                        }

                        std::cout << "----------------------\n";
                        std::cout << "판매할 무기 번호 선택 >> ";
                        int choice;
                        std::cin >> choice;

                        // 2. 무기 상세 정보 및 판매 확인
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            int qty = items.at(itemId);
                            displaySellDetail(weaponDB[itemId].base, weaponDB[itemId].attack, "공격력", qty);

                            int confirm;
                            std::cin >> confirm;

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
                std::cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                    {
                        // 방어구 구매 시스템
                        std::cout << "\n=== 방어구 구매 목록 ===\n";
                        int index = 1;
                        std::map<int, int> indexToID;

                        // 방어구 목록 출력
                        for (auto& pair : armorDB)
                        {
                            if (!pair.second.base.canBuy) continue;
                            std::cout << "[" << index << "] " << pair.second.base.name << "\n";
                            indexToID[index] = pair.first;
                            index++;
                        }

                        std::cout << "----------------------\n";
                        std::cout << "확인할 방어구 번호 선택 >> ";
                        int choice;
                        std::cin >> choice;

                        // 방어구 상세 정보 확인 및 최종 승인 절차
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            auto& selectedArmor = armorDB[itemId];

                            displayBuyDetail(armorDB[itemId].base, armorDB[itemId].defense, "방어력");

                            int confirm;
                            std::cin >> confirm;

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

                                        std::cout << "\n[!] " << selectedArmor.base.name << " 1개를 구매했습니다!\n";
                                        std::cout << "현재 남은 금화: " << player->getGold() << "G\n";
                                    }
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
                        // 방어구 판매 시스템
                        std::cout << "\n=== 소지 방어구 목록 ===\n";
                        int index = 1;
                        std::map<int, int> indexToID;

                        if (player->getInventory() == nullptr)
                        {
                            std::cout << "인벤토리 정보를 불러올 수 없습니다.\n";
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
                                std::cout << "[" << index << "] " << armorDB[itemId].base.name
                                    << " (보유: " << count << "개)\n";
                                indexToID[index] = itemId;
                                index++;
                            }
                        }

                        if (index == 1)
                        {
                            std::cout << "판매할 방어구가 없습니다.\n";
                            break;
                        }

                        std::cout << "----------------------\n";
                        std::cout << "판매할 방어구 번호 선택 >> ";
                        int choice;
                        std::cin >> choice;

                        // 방어구 상세 정보 확인 및 최종 승인 절차
                        if (indexToID.count(choice))
                        {
                            int itemId = indexToID[choice];
                            auto& selectedArmor = armorDB[itemId];
                            int currentCount = items.at(itemId);

                            displaySellDetail(selectedArmor.base, selectedArmor.defense, "방어력", currentCount);

                            int confirm;
                            std::cin >> confirm;

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
                std::cout << "\n=== 소모품 상점 ===\n";
                int index = 1;
                std::map<int, int> indexToID;

                // 구매 가능한 소모품 목록 출력 (이름만 출력)
                for (auto& pair : consumableDB)
                {
                    if (!pair.second.base.canBuy) continue;
                    std::cout << "[" << index << "] " << pair.second.base.name << "\n";
                    indexToID[index] = pair.first;
                    index++;
                }

                if (index == 1)
                {
                    std::cout << "현재 판매 중인 소모품이 없습니다.\n";
                    break;
                }

                std::cout << "------------------\n";
                std::cout << "확인할 소모품 번호 선택 >> ";
                int choiceIndex;
                std::cin >> choiceIndex;

                // 소모품의 상세 정보 출력 및 수량 입력
                if (indexToID.count(choiceIndex))
                {
                    int itemId = indexToID[choiceIndex];
                    auto& selectedItem = consumableDB[itemId];

                    std::cout << "\n--- [ " << selectedItem.base.name << " ] ---\n";
                    std::cout << "가격   : " << selectedItem.base.price << "G\n";
                    std::cout << "회복량 : " << selectedItem.hp << " HP\n";
                    std::cout << "------------------------\n";

                    std::cout << "구매할 수량을 입력하세요 >> ";
                    int qty;
                    std::cin >> qty;

                    if (qty <= 0)
                    {
                        std::cout << "1개 이상의 수량을 입력해야 합니다.\n";
                        break;
                    }

                    // 총 가격을 계산하고 입력한 갯수도 반환함
                    int totalPrice = selectedItem.base.price * qty;

                    std::cout << "총 가격: " << totalPrice << "G (" << qty << "개)\n";
                    std::cout << "구매하시겠습니까? (1.예 / 2.아니오) >> ";

                    int confirm;
                    std::cin >> confirm;

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

#include "ShopSystem.h"
#include "ShopUI.h"
#include "ShopLogic.h"
#include "../Item/ItemDB.h"
#include <iostream>
#include <iomanip>

// 상점
void ShopSystem::showShopMenu(int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    while (true) {

        displayShop(playerGold);
        cout << "선택 >> ";

        int menuchoice;
        cin >> menuchoice;

        if (menuchoice == 0) break;

        switch (menuchoice) {
        //무기 구매 및 판매 시스템
        case 1: {

            cout << "\n=== 무기 ===\n";
            cout << "1. 구매\n";
            cout << "2. 판매\n";
            cout << "선택 >> ";

            int subChoice;
            cin >> subChoice;

            switch (subChoice) {

                // 무기 구매 시스템
            case 1: {
                cout << "\n=== 무기 구매 ===\n";
                int index = 1;
                map<int, int> indexToID;

                for (auto& pair : weaponDB) {
                    if (!pair.second.base.canBuy) continue;

                    cout << "[" << index << "] "
                        << pair.second.base.name
                        << " (가격: " << pair.second.base.price << "G)\n";

                    indexToID[index] = pair.first;
                    index++;
                }

                cout << "번호 선택 >> ";
                int choice;
                cin >> choice;

                if (indexToID.count(choice)) {
                    int itemId = indexToID[choice];

                    cout << "수량 >> ";
                    int qty;
                    cin >> qty;

                    int totalPrice = weaponDB[itemId].base.price * qty;

                    if (playerGold >= totalPrice) {
                        playerGold -= totalPrice;
                        playerWeapons[itemId] += qty;

                        cout << "구매 완료!\n";
                    }
                    else {
                        cout << "금화 부족\n";
                    }
                }
                break;
            }
                  // 무기 판매 시스템
            case 2: {
                cout << "\n=== 무기 판매 ===\n";
                int index = 1;
                map<int, int> indexToID;

                for (auto& pair : playerWeapons) {
                    if (pair.second <= 0) continue;

                    int itemId = pair.first;

                    cout << "[" << index << "] "
                        << weaponDB[itemId].base.name
                        << " (수량: " << pair.second
                        << ", 판매가: " << weaponDB[itemId].base.sellprice << "G)\n";

                    indexToID[index] = itemId;
                    index++;
                }

                if (index == 1) {
                    cout << "판매할 무기가 없습니다.\n";
                    break;
                }

                cout << "번호 선택 >> ";
                int choice;
                cin >> choice;

                if (indexToID.count(choice)) {
                    int itemId = indexToID[choice];

                    cout << "수량 >> ";
                    int qty;
                    cin >> qty;

                    if (playerWeapons[itemId] >= qty) {
                        playerWeapons[itemId] -= qty;

                        int gold = weaponDB[itemId].base.sellprice * qty;
                        playerGold += gold;

                        cout << "판매 완료!\n";
                    }
                    else {
                        cout << "수량 부족\n";
                    }
                }
                break;
            }

            default:
                cout << "잘못된 선택\n";
            }

            break;
        }

        // 방어구 메뉴
case 2: { 
    cout << "\n=== 방어구 ===\n";
    cout << "1. 구매\n";
    cout << "2. 판매\n";
    cout << "선택 >> ";

    int subChoice;
    cin >> subChoice;

    switch (subChoice) {

        // 방어구 구매 시스템
    case 1: {
        cout << "\n=== 방어구 구매 ===\n";
        int index = 1;
        map<int, int> indexToID;

        for (auto& pair : armorDB) {
            if (!pair.second.base.canBuy) continue;

            cout << "[" << index << "] "
                << pair.second.base.name
                << " (가격: " << pair.second.base.price << "G)\n";

            indexToID[index] = pair.first;
            index++;
        }

        cout << "번호 선택 >> ";
        int choice;
        cin >> choice;

        if (indexToID.count(choice)) {
            int itemId = indexToID[choice];

            cout << "수량 >> ";
            int qty;
            cin >> qty;

            int totalPrice = armorDB[itemId].base.price * qty;

            if (playerGold >= totalPrice) {
                playerGold -= totalPrice;
                playerArmors[itemId] += qty;

                cout << "구매 완료!\n";
            }
            else {
                cout << "금화 부족\n";
            }
        }
        break;
    }

          // 방어구 판매 시스템
    case 2: {
        cout << "\n=== 방어구 ===\n";
        int index = 1;
        map<int, int> indexToID;

        for (auto& pair : playerArmors) {
            if (pair.second <= 0) continue;

            int itemId = pair.first;

            cout << "[" << index << "] "
                << armorDB[itemId].base.name
                << " (수량: " << pair.second
                << ", 판매가: " << armorDB[itemId].base.sellprice << "G)\n";

            indexToID[index] = itemId;
            index++;
        }

        if (index == 1) {
            cout << "판매할 방어구가 없습니다.\n";
            break;
        }

        cout << "번호 선택 >> ";
        int choice;
        cin >> choice;

        if (indexToID.count(choice)) {
            int itemId = indexToID[choice];

            cout << "수량 >> ";
            int qty;
            cin >> qty;

            if (playerArmors[itemId] >= qty) {
                playerArmors[itemId] -= qty;

                int gold = armorDB[itemId].base.sellprice * qty;
                playerGold += gold;

                cout << "판매 완료!\n";
            }
            else {
                cout << "수량 부족\n";
            }
        }
        break;
    }

    default:
        cout << "잘못된 선택\n";
    }

    break;
}
        // 소모품 구매 시스템
        case 3: { 
            cout << "\n=== 소모품 구매 ===" << '\n';
            int index = 1;
            map<int, int> indexToID; // 화면 번호 → 아이템 ID

            // 구매 가능한 소모품만 DB에서 출력
            for (auto& pair : consumableDB) {
                if (!pair.second.base.canBuy) continue;

                cout << "[" << index << "] "
                    << pair.second.base.name
                    << " (가격: " << pair.second.base.price
                    << "G, 회복량: " << pair.second.hp << ")" << '\n';

                indexToID[index] = pair.first;
                index++;
            }

            cout << "\n==================" << '\n';
            cout << "구매할 소모품 번호 입력 >> ";
            int choiceIndex;
            cin >> choiceIndex;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (indexToID.count(choiceIndex)) {
                int itemId = indexToID[choiceIndex];

                cout << "수량 >> ";
                int qty;
                cin >> qty;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                buyItem(itemId, ItemType::Consumable, qty, playerGold,
                    playerWeapons, playerArmors, playerConsumables, playerLoot);
            }
            else {
                cout << "잘못된 선택입니다.\n";
            }
            break;
        }
        case 4: {
            cout << "\n=== 전리품 판매 ===" << '\n';
            int index = 1;
            map<int, int> indexToID;

            for (auto& pair : playerLoot) {
                int itemId = pair.first;
                int qtyOwned = pair.second;

                if (qtyOwned <= 0) continue;

                cout << "[" << index << "] "
                    << LootDB[itemId].base.name
                    << " (수량: " << qtyOwned
                    << ", 판매가: " << LootDB[itemId].base.sellprice << "G)" << '\n';

                indexToID[index] = itemId;
                index++;
            }

            if (index == 1) {
                cout << "판매할 전리품이 없습니다.\n";
                break;
            }

            cout << "번호 선택 >> ";
            int choiceIndex;
            cin >> choiceIndex;

            if (indexToID.count(choiceIndex)) {
                int itemId = indexToID[choiceIndex];

                cout << "수량 >> ";
                int qty;
                cin >> qty;

                if (playerLoot[itemId] >= qty) {
                    playerLoot[itemId] -= qty;

                    int goldEarned = LootDB[itemId].base.sellprice * qty;
                    playerGold += goldEarned;

                    cout << LootDB[itemId].base.name << " "
                        << qty << "개 판매 완료!\n";
                }
                else {
                    cout << "수량 부족\n";
                }
            }
            else {
                cout << "잘못된 선택\n";
            }
            break;
        }
        default:
            cout << "잘못된 입력입니다.\n";
        }
    }
}
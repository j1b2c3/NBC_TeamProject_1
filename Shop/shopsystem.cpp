#include "ShopSystem.h"
#include <iomanip>
#include <iostream>
#include "ShopLogic.h"
#include "ShopUI.h"
#include "../Item/ItemDB.h"

// 상점 메뉴 
void ShopSystem::showShopMenu(int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    while (true) {

        displayshop(playerGold);
        cout << "선택 >> ";

        int menuchoice;
        cin >> menuchoice;

        if (menuchoice == 0) break;

        switch (menuchoice) {
        case 1: { // 메인 메뉴의 '무기 상점' 진입
            std::cout << "\n=== 무기 메뉴 ===\n";
            std::cout << "1. 구매\n";
            std::cout << "2. 판매\n";
            std::cout << "선택 >> ";

            int subChoice;
            std::cin >> subChoice;

            switch (subChoice) {
            case 1: { // 무기 구매 시스템
                std::cout << "\n=== 무기 구매 목록 ===\n";
                int index = 1;
                std::map<int, int> indexToID;

                // 무기 목록 출력 (이름만 출력)
                for (auto& pair : weaponDB) {
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
                if (indexToID.count(choice)) {
                    int itemId = indexToID[choice];
                    auto& selectedWeapon = weaponDB[itemId];

                    std::cout << "\n--- [ " << selectedWeapon.base.name << " ] ---\n";
                    std::cout << "가격   : " << selectedWeapon.base.price << "G\n";
                    std::cout << "공격력 : " << selectedWeapon.attack << "\n";
                    std::cout << "------------------------\n";
                    std::cout << "구매하시겠습니까? (1.예 / 2.아니오) >> ";

                    int confirm;
                    std::cin >> confirm;

                    if (confirm == 1) {
                        if (playerGold >= selectedWeapon.base.price) {
                            playerGold -= selectedWeapon.base.price;
                            playerWeapons[itemId] += 1;
                            std::cout << "\n[!] " << selectedWeapon.base.name << " 1개를 구매했습니다!\n";
                            std::cout << "현재 남은 금화: " << playerGold << "G\n";
                        }
                        else {
                            std::cout << "\n[X] 금화가 부족합니다.\n";
                        }
                    }
                    else {
                        std::cout << "구매를 취소했습니다.\n";
                    }
                }
                else {
                    std::cout << "잘못된 번호입니다.\n";
                }
                break;
            }

            case 2: { // 무기 판매 시스템
                std::cout << "\n=== 소지 무기 목록 ===\n";
                int index = 1;
                std::map<int, int> indexToID;

                // 소지한 무기 목록 출력 ( 이름만 출력)
                for (auto& pair : playerWeapons) {
                    if (pair.second <= 0) continue;
                    int itemId = pair.first;
                    std::cout << "[" << index << "] " << weaponDB[itemId].base.name
                        << " (보유: " << pair.second << "개)\n";
                    indexToID[index] = itemId;
                    index++;
                }

                if (index == 1) {
                    std::cout << "판매할 무기가 없습니다.\n";
                    break;
                }

                std::cout << "----------------------\n";
                std::cout << "판매할 무기 번호 선택 >> ";
                int choice;
                std::cin >> choice;

                // 2. 무기 상세 정보 및 판매 확인
                if (indexToID.count(choice)) {
                    int itemId = indexToID[choice];
                    auto& selectedWeapon = weaponDB[itemId];

                    std::cout << "\n--- [ " << selectedWeapon.base.name << " 판매 ] ---\n";
                    std::cout << "공격력 : " << selectedWeapon.attack << "\n";
                    std::cout << "판매가 : " << selectedWeapon.base.sellprice << "G\n";
                    std::cout << "현재 보유량: " << playerWeapons[itemId] << "개\n";
                    std::cout << "------------------------\n";
                    std::cout << "정말 판매하시겠습니까? (1.예 / 2.아니오) >> ";

                    int confirm;
                    std::cin >> confirm;

                    if (confirm == 1) {
                        playerWeapons[itemId] -= 1;
                        playerGold += selectedWeapon.base.sellprice;
                        std::cout << "\n[!] " << selectedWeapon.base.name << " 1개를 판매했습니다.\n";
                        std::cout << "현재 남은 금화: " << playerGold << "G\n";
                    }
                    else {
                        std::cout << "판매를 취소했습니다.\n";
                    }
                }
                else {
                    std::cout << "잘못된 번호입니다.\n";
                }
                break;
            }
            default:
                std::cout << "잘못된 메뉴 선택입니다.\n";
                break;
            }
            break; // 무기의 케이스 종료 ->  상점메뉴로 되돌아감
        }
case 2: { // 메인 메뉴의 '방어구 상점' 진입
    std::cout << "\n=== 방어구 메뉴 ===\n";
    std::cout << "1. 구매\n";
    std::cout << "2. 판매\n";
    std::cout << "선택 >> ";

    int subChoice;
    std::cin >> subChoice;

    switch (subChoice) {
        case 1: { // 방어구 구매 시스템
            std::cout << "\n=== 방어구 구매 목록 ===\n";
            int index = 1;
            std::map<int, int> indexToID;

            // 방어구 목록 출력
            for (auto& pair : armorDB) {
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
            if (indexToID.count(choice)) {
                int itemId = indexToID[choice];
                auto& selectedArmor = armorDB[itemId];

                std::cout << "\n--- [ " << selectedArmor.base.name << " ] ---\n";
                std::cout << "가격   : " << selectedArmor.base.price << "G\n";
                std::cout << "방어력 : " << selectedArmor.defense << "\n";
                std::cout << "------------------------\n";
                std::cout << "구매하시겠습니까? (1.예 / 2.아니오) >> ";

                int confirm;
                std::cin >> confirm;

                if (confirm == 1) {
                    if (playerGold >= selectedArmor.base.price) {
                        playerGold -= selectedArmor.base.price;
                        playerArmors[itemId] += 1;
                        std::cout << "\n[!] " << selectedArmor.base.name << " 1개를 구매했습니다!\n";
                        std::cout << "현재 남은 금화: " << playerGold << "G\n";
                    } else {
                        std::cout << "\n[X] 금화가 부족합니다.\n";
                    }
                } else {
                    std::cout << "구매를 취소했습니다.\n";
                }
            } else {
                std::cout << "잘못된 번호입니다.\n";
            }
            break;
        }

        case 2: { // 방어구 판매 시스템
            std::cout << "\n=== 소지 방어구 목록 ===\n";
            int index = 1;
            std::map<int, int> indexToID;

            // 소지한 방어구 목록 출력 만약 아무것도 없다면 상점메뉴로 이동
            for (auto& pair : playerArmors) {
                if (pair.second <= 0) continue;
                int itemId = pair.first;
                std::cout << "[" << index << "] " << armorDB[itemId].base.name
                          << " (보유: " << pair.second << "개)\n";
                indexToID[index] = itemId;
                index++;
            }

            if (index == 1) {
                std::cout << "판매할 방어구가 없습니다.\n";
                break;
            }

            std::cout << "----------------------\n";
            std::cout << "판매할 방어구 번호 선택 >> ";
            int choice;
            std::cin >> choice;

            // 방어구 상세 정보 확인 및 최종 승인 절차
            if (indexToID.count(choice)) {
                int itemId = indexToID[choice];
                auto& selectedArmor = armorDB[itemId];

                std::cout << "\n--- [ " << selectedArmor.base.name << " 판매 ] ---\n";
                std::cout << "방어력 : " << selectedArmor.defense << "\n";
                std::cout << "판매가 : " << selectedArmor.base.sellprice << "G\n"; 
                std::cout << "현재 보유량: " << playerArmors[itemId] << "개\n";
                std::cout << "------------------------\n";
                std::cout << "정말 판매하시겠습니까? (1.예 / 2.아니오) >> ";

                int confirm;
                std::cin >> confirm;

                if (confirm == 1) {
                    playerArmors[itemId] -= 1;
                    playerGold += selectedArmor.base.sellprice;
                    std::cout << "\n[!] " << selectedArmor.base.name << " 1개를 판매했습니다.\n";
                    std::cout << "현재 남은 금화: " << playerGold << "G\n";
                } else {
                    std::cout << "판매를 취소했습니다.\n";
                }
            } else {
                std::cout << "잘못된 번호입니다.\n";
            }
            break;
        }
        default:
            std::cout << "잘못된 메뉴 선택입니다.\n";
            break;
    }
    break; 
}
// 소모품 메뉴 (구매만 허용하고 판매는 불가)
case 3: {
    std::cout << "\n=== 소모품 상점 ===\n";
    int index = 1;
    std::map<int, int> indexToID;

    // 구매 가능한 소모품 목록 출력 (이름만 출력)
    for (auto& pair : consumableDB) {
        if (!pair.second.base.canBuy) continue;

        std::cout << "[" << index << "] " << pair.second.base.name << "\n";
        indexToID[index] = pair.first;
        index++;
    }

    if (index == 1) {
        std::cout << "현재 판매 중인 소모품이 없습니다.\n";
        break;
    }

    std::cout << "------------------\n";
    std::cout << "확인할 소모품 번호 선택 >> ";
    int choiceIndex;
    std::cin >> choiceIndex;

    // 소모품의 상세 정보 출력 및 수량 입력
    if (indexToID.count(choiceIndex)) {
        int itemId = indexToID[choiceIndex];
        auto& selectedItem = consumableDB[itemId];

        std::cout << "\n--- [ " << selectedItem.base.name << " ] ---\n";
        std::cout << "가격   : " << selectedItem.base.price << "G\n";
        std::cout << "회복량 : " << selectedItem.hp << " HP\n";
        std::cout << "------------------------\n";

        std::cout << "구매할 수량을 입력하세요 >> ";
        int qty;
        std::cin >> qty;

        if (qty <= 0) {
            std::cout << "1개 이상의 수량을 입력해야 합니다.\n";
            break;
        }

        // 총 가격을 계산하고 입력한 갯수도 반환함
        int totalPrice = selectedItem.base.price * qty;

        std::cout << "총 가격: " << totalPrice << "G (" << qty << "개)\n";
        std::cout << "구매하시겠습니까? (1.예 / 2.아니오) >> ";

        int confirm;
        std::cin >> confirm;

        if (confirm == 1) {
            if (playerGold >= totalPrice) {
                playerGold -= totalPrice;
                playerConsumables[itemId] += qty; // 인벤토리에 수량만큼 추가

                std::cout << "\n[!] " << selectedItem.base.name << " " << qty << "개를 구매했습니다!\n";
                std::cout << "현재 남은 금화: " << playerGold << "G\n";
            }
            else {
                std::cout << "\n[X] 금화가 부족합니다. (부족한 금액: " << (totalPrice - playerGold) << "G)\n";
            }
        }
        else {
            std::cout << "구매를 취소했습니다.\n";
        }
    }
    else {
        std::cout << "잘못된 선택입니다.\n";
    }
    break;
}
        case 4: {
            cout << "\n=== 전리품 판매 ===" << endl;
            int index = 1;
            map<int, int> indexToID;

            for (auto& pair : playerLoot) {
                int itemId = pair.first;
                int qtyOwned = pair.second;

                if (qtyOwned <= 0) continue;

                cout << "[" << index << "] "
                    << LootDB[itemId].base.name
                    << " (수량: " << qtyOwned
                    << ", 판매가: " << LootDB[itemId].base.sellprice << "G)" << endl;

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

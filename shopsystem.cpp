#include "shopsystem.h"

// ----------------- 구매 -----------------
void ShopSystem::buyItem(int id, ItemType type, int amount,
    int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    int cost = 0;
    bool canBuy = true;

    switch (type) {
    case ItemType::Weapon:
        cost = weaponDB[id].base.price * amount;
        canBuy = weaponDB[id].base.canBuy;
        break;
    case ItemType::Armor:
        cost = armorDB[id].base.price * amount;
        canBuy = armorDB[id].base.canBuy;
        break;
    case ItemType::Consumable:
        cost = consumableDB[id].base.price * amount;
        canBuy = consumableDB[id].base.canBuy;
        break;
    case ItemType::Loot:
        cost = LootDB[id].base.price * amount;
        canBuy = LootDB[id].base.canBuy;
        break;
    default: break;
    }

    if (!canBuy) {
        cout << "이 아이템은 구매할 수 없습니다.\n";
        return;
    }

    if (playerGold < cost) {
        cout << "금화가 부족합니다. 필요 금화 : " << cost << "\n";
        return;
    }

    playerGold -= cost;

    switch (type) {
    case ItemType::Weapon: playerWeapons[id] += amount; break;
    case ItemType::Armor: playerArmors[id] += amount; break;
    case ItemType::Consumable: playerConsumables[id] += amount; break;
    case ItemType::Loot: playerLoot[id] += amount; break;
    default: break;
    }

    cout << "구매 완료! " << amount << "개, 금화 -" << cost << "\n";
}

// ----------------- 판매 -----------------
void ShopSystem::sellItem(int id, ItemType type,
    int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    int qty = 0;
    int gold = 0;

    switch (type) {
    case ItemType::Weapon:
        qty = playerWeapons[id];
        gold = qty * weaponDB[id].base.sellprice;
        playerWeapons.erase(id);
        break;
    case ItemType::Armor:
        qty = playerArmors[id];
        gold = qty * armorDB[id].base.sellprice;
        playerArmors.erase(id);
        break;
    case ItemType::Consumable:
        qty = playerConsumables[id];
        gold = qty * consumableDB[id].base.sellprice;
        playerConsumables.erase(id);
        break;
    case ItemType::Loot:
        qty = playerLoot[id];
        gold = qty * LootDB[id].base.sellprice;
        playerLoot.erase(id);
        break;
    default: break;
    }

    playerGold += gold;
    cout << "판매 완료! 금화 +" << gold << "\n";
}

void ShopSystem::showInventoryUI(int playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    // 총 폭 계산: 12 + 26 + 6 + 구분자 4 = 약 48
    cout << "┌──────────────────────────────────────────────┐\n";
    cout << "│              플레이어 인벤토리               │\n";
    cout << "├──────────────────────────────────────────────┤\n";

    // 헤더
    cout << "│"
        << left << setw(12) << "종류"
        << "│"
        << left << setw(26) << "이름"
        << "│"
        << right << setw(6) << "개수"
        << "│\n";

    cout << "├──────────────────────────────────────────────┤\n";

    // 출력 함수
    auto printItemRow = [](string typeName, string name, int qty) {
        cout << "│"
            << left << setw(12) << typeName
            << "│"
            << left << setw(26) << name
            << "│"
            << right << setw(6) << qty
            << "│\n";
        };

    // 아이템 출력
    for (auto& [id, qty] : playerWeapons)
        printItemRow("무기", weaponDB[id].base.name, qty);
    for (auto& [id, qty] : playerArmors)
        printItemRow("방어구", armorDB[id].base.name, qty);
    for (auto& [id, qty] : playerConsumables)
        printItemRow("소모품", consumableDB[id].base.name, qty);
    for (auto& [id, qty] : playerLoot)
        printItemRow("전리품", LootDB[id].base.name, qty);

    cout << "├──────────────────────────────────────────────┤\n";


    cout << "│ 금화 : "
        << left << setw(37) << playerGold << " │\n";

    cout << "└──────────────────────────────────────────────┘\n";

    cout << "\n아무 키나 입력하면 돌아갑니다 >> ";
    cin.ignore();
    cin.get();
}

// ----------------- 아즈키 스타일 상점 메뉴 -----------------
void ShopSystem::showShopMenu(int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    while (true) {
        cout << "\n";
        cout << "┌────────────────────────────────────┐\n";
        cout << "|                   상점             |\n";
        cout << "|────────────────────────────────────|\n";
        cout << "| 금화: " << setw(15) << playerGold << "              |\n";
        cout << "|────────────────────────────────────|\n";
        cout << "| [1] 무기 구매       [2] 방어구 구매|\n";
        cout << "| [3] 소모품 구매     [4] 전리품 판매|\n";
        cout << "| [5] 인벤토리 확인   [0] 상점 종료  |\n";
        cout << "└────────────────────────────────────┘\n";
        cout << "선택 >> ";
        
        int menuchoice;
        cin >> menuchoice;

        if (menuchoice == 0) break;

        switch (menuchoice) {
        //무기 구매 및 판매 시스템
        case 1: {

            cout << "\n=== 무기 메뉴 ===\n";
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
    cout << "\n=== 방어구 메뉴 ===\n";
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
        cout << "\n=== 방어구 판매 ===\n";
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
            cout << "\n=== 소모품 구매 ===" << endl;
            int index = 1;
            map<int, int> indexToID; // 화면 번호 → 아이템 ID

            // 구매 가능한 소모품만 DB에서 출력
            for (auto& pair : consumableDB) {
                if (!pair.second.base.canBuy) continue;

                cout << "[" << index << "] "
                    << pair.second.base.name
                    << " (가격: " << pair.second.base.price
                    << "G, 회복량: " << pair.second.hp << ")" << endl;

                indexToID[index] = pair.first;
                index++;
            }

            cout << "\n==================" << endl;
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

                ShopSystem::buyItem(itemId, ItemType::Consumable, qty, playerGold,
                    playerWeapons, playerArmors, playerConsumables, playerLoot);
            }
            else {
                cout << "잘못된 선택입니다.\n";
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
        case 5:
            ShopSystem::showInventoryUI(playerGold, playerWeapons, playerArmors, playerConsumables, playerLoot);
            break;
        default:
            cout << "잘못된 입력입니다.\n";
        }
    }
}
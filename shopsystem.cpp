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

// ----------------- 아즈키 스타일 인벤토리 -----------------
void ShopSystem::showInventoryUI(int playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot)
{
    cout << "┌───────────────────────────┐\n";
    cout << "│       플레이어 인벤토리   │\n";
    cout << "├─────┬─────────────┬───────┤\n";
    cout << "│종류 │ 이름        │ 개수  │\n";
    cout << "├─────┼─────────────┼───────┤\n";

    auto printItemRow = [](string typeName, string name, int qty) {
        cout << "│" << setw(5) << typeName
            << "│" << setw(13) << name
            << "│" << setw(7) << qty
            << "│\n";
        };

    for (auto& [id, qty] : playerWeapons)
        printItemRow("무기", weaponDB[id].base.name, qty);
    for (auto& [id, qty] : playerArmors)
        printItemRow("방어구", armorDB[id].base.name, qty);
    for (auto& [id, qty] : playerConsumables)
        printItemRow("소모품", consumableDB[id].base.name, qty);
    for (auto& [id, qty] : playerLoot)
        printItemRow("전리품", LootDB[id].base.name, qty);

    cout << "├───────────────────────────┤\n";
    cout << "│ 금화 : " << playerGold << setw(18) << " │\n";
    cout << "└────────────────────────────┘\n";
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
        cout << "|============================================|\n";
        cout << "|                   상점                     |\n";
        cout << "|============================================|\n";
        cout << "| 금화: " << setw(36) << playerGold << " |\n";
        cout << "|============================================|\n";
        cout << "| [1] 무기 구매       [2] 방어구 구매        |\n";
        cout << "| [3] 소모품 구매     [4] 전리품 판매        |\n";
        cout << "| [5] 인벤토리 확인   [0] 상점 종료          |\n";
        cout << "|============================================|\n";
        cout << "선택 >> ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        int id, qty;
        switch (choice) {
        //무기 구매 시스템
        case 1: {
            cout << "\n=== 무기 구매 ===" << endl;
            int index = 1;
            map<int, int> indexToID; // 화면 번호 → 아이템 ID

            // 구매 가능한 무기만 DB에서 출력
            for (auto& pair : weaponDB) {
                if (!pair.second.base.canBuy) continue;

                cout << "[" << index << "] "
                    << pair.second.base.name
                    << " (가격: " << pair.second.base.price
                    << "G, 공격력: " << pair.second.attack << ")" << endl;

                indexToID[index] = pair.first;
                index++;
            }
            cout << "\n==================" << endl;
            cout << "구매할 무기 번호 입력 >> ";
            int choiceIndex;
            cin >> choiceIndex;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (indexToID.count(choiceIndex)) {
                int itemId = indexToID[choiceIndex];

                cout << "수량 >> ";
                int qty;
                cin >> qty;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                ShopSystem::buyItem(itemId, ItemType::Weapon, qty, playerGold,
                    playerWeapons, playerArmors, playerConsumables, playerLoot);
            }
            else {
                cout << "잘못된 선택입니다.\n";
            }
            break;
        }
        //방어구 구매 시스템
        case 2: { 
            cout << "\n=== 방어구 구매 ===" << endl;
            int index = 1;
            map<int, int> indexToID; // 화면 번호 → 아이템 ID

            // 구매 가능한 방어구만 DB에서 출력
            for (auto& pair : armorDB) {
                if (!pair.second.base.canBuy) continue;

                cout << "[" << index << "] "
                    << pair.second.base.name
                    << " (가격: " << pair.second.base.price
                    << "G, 방어력: " << pair.second.defense << ")" << endl;

                indexToID[index] = pair.first;
                index++;
            }

            cout << "\n==================" << endl;
            cout << "구매할 방어구 번호 입력 >> ";
            int choiceIndex;
            cin >> choiceIndex;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (indexToID.count(choiceIndex)) {
                int itemId = indexToID[choiceIndex];

                cout << "수량 >> ";
                int qty;
                cin >> qty;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                ShopSystem::buyItem(itemId, ItemType::Armor, qty, playerGold,
                    playerWeapons, playerArmors, playerConsumables, playerLoot);
            }
            else {
                cout << "잘못된 선택입니다.\n";
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
        case 5:
            ShopSystem::showInventoryUI(playerGold, playerWeapons, playerArmors, playerConsumables, playerLoot);
            break;
        default:
            cout << "잘못된 입력입니다.\n";
        }
    }
}
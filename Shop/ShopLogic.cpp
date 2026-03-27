#include "ShopLogic.h"
#include <iostream>
using namespace std;

// 구매
void buyItem(int id, ItemType type, int amount,
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
    }

    if (!canBuy) {
        cout << "이 아이템은 구매할 수 없습니다.\n";
        return;
    }

    if (playerGold < cost) {
        cout << "금화 부족\n";
        return;
    }

    playerGold -= cost;

    switch (type) {
    case ItemType::Weapon: playerWeapons[id] += amount; break;
    case ItemType::Armor: playerArmors[id] += amount; break;
    case ItemType::Consumable: playerConsumables[id] += amount; break;
    case ItemType::Loot: playerLoot[id] += amount; break;
    }

    cout << "구매 완료!\n";
}

// 판매
void sellItem(int id, ItemType type,
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
    }

    playerGold += gold;
    cout << "판매 완료! +" << gold << "G\n";
}
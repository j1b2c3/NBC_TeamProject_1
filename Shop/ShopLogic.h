#pragma once
#include "../Item/ItemDB.h"
#include <map>

void buyItem(int id, ItemType type, int amount,
    int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot);

void sellItem(int id, ItemType type,
    int& playerGold,
    map<int, int>& playerWeapons,
    map<int, int>& playerArmors,
    map<int, int>& playerConsumables,
    map<int, int>& playerLoot);
#pragma once
#include <vector>
#include <string>
#include "ItemDB.h"
#include "Inventory.h"
#include "../Player/Player/player.h"

struct ItemInfo 
{
    std::string name;
    int count;
    std::string desc;
};

void displayInventory(int playerGold, const std::vector<ItemInfo>& weapons, 
                        const std::vector<ItemInfo>& armors, 
                        const std::vector<ItemInfo>& consumables);

void showInventoryUI(Inventory& inventory, Player& player);

void showConsumableListUI(const std::map<int, int>& consumables);
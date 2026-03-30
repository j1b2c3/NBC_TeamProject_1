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

void displayInventory(int playerGold, const Inventory& inventory,
                        const std::vector<ItemInfo>& weapons,
                        const std::vector<ItemInfo>& armors,
                        const std::vector<ItemInfo>& consumables);

void showInventoryUI(Inventory& inventory, Player& player);

void showConsumableListUI(const std::map<int, int>& consumables);

void displayInventoryHeader();

void handleWeaponAction(Inventory& inventory, Player& player, const std::vector<ItemInfo>& weapons);
void handleArmorAction(Inventory& inventory, Player& player, const std::vector<ItemInfo>& armors);
void handleConsumableAction(Inventory& inventory, Player& player, const std::vector<ItemInfo>& consumables);
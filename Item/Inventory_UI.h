#pragma once
#include <vector>
#include <string>
#include "ItemDB.h"
#include "Inventory.h"
#include "../Player/Player/player.h"

void displayInventory(Player& player);

void showInventoryUI(Player& player);

void showConsumableListUI(const std::map<int, int>& consumables);

void displayInventoryHeader();

void handleWeaponAction(Player& player);
void handleArmorAction(Player& player);
void handleConsumableAction(Player& player);

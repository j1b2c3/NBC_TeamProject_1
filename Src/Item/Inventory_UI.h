#pragma once

#include "Inventory.h"
#include "../System/util.h"
#include "../System/Windows.h"

void displayInventory(Player& player);

void showInventoryUI(Player& player);

void showConsumableListUI(Player& player);

void displayInventoryHeader();

void handleWeaponAction(Player& player);
void handleArmorAction(Player& player);
void handleConsumableAction(Player& player);

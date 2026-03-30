#pragma once
#include "../Item/ItemDB.h"

void displayShop(int playerGold);

void displayWeaponMenu();

void displayWeaponDetail(const Weapon& weapon);

void displayWeaponSellDetail(const Weapon& weapon, int ownedCount);

void displayArmorMenu();

void displayArmorDetail(const Armor& armor);

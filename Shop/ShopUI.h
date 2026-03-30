#pragma once
#include "../Item/ItemDB.h"

void displayShop(int playerGold);

void displayShopMeun(std::string title);

void displayBuyDetail(const ItemBase& base, int statValue, std::string statName);

void displaySellDetail(const ItemBase& base, int statValue, std::string statName, int ownedCount);

void displayNoGold();

void displayBuyCancel();

void displaySellCancel();

void displayNoNumber();


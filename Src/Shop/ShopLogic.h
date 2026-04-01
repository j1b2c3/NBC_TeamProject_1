#pragma once
#include "../Item/ItemDB.h"
#include "../Player/Player/Player.h"
#include <map>

void buyItem(int id, ItemType type, int amount, Player* player);

void sellItem(int id, ItemType type, int amount, Player* player);

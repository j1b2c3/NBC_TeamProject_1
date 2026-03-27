#pragma once
#include <vector>
#include "ItemDB.h"

struct ItemInfo;

void displayInventory(int playerGold, const vector<ItemInfo>& weapons, const vector<ItemInfo>& armors, const vector<ItemInfo>& consumables);

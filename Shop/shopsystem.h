#pragma once
#include "../Item/ItemDB.h"
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

class ShopSystem {
public:
    // 아즈키 스타일 인벤토리 출력
    static void showInventoryUI(int playerGold,
        map<int, int>& playerWeapons,
        map<int, int>& playerArmors,
        map<int, int>& playerConsumables,
        map<int, int>& playerLoot);

    // 상점 메뉴 실행 (아즈키코드 스타일)
    static void showShopMenu(int& playerGold,
        map<int, int>& playerWeapons,
        map<int, int>& playerArmors,
        map<int, int>& playerConsumables,
        map<int, int>& playerLoot);
};
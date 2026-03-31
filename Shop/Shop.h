#pragma once
#include "../Item/ItemDB.h"
#include "../Player/Player/Player.h"
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

class Shop {
public:
    // 상점 메뉴 실행 (아즈키코드 스타일)
    static void ShowShopMenu(Player* player);
};

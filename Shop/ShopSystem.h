#pragma once
#include "../Item/ItemDB.h"
#include "../Player/Player/Player.h"
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;

class ShopSystem {
public:
    // 아즈키 스타일 인벤토리 출력
    static void showInventoryUI(Player* player);

    // 상점 메뉴 실행 (아즈키코드 스타일)
    static void showShopMenu(Player* player);
};
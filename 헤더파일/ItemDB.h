#pragma once
#include <string>
#include <map>

using namespace std;

// 아이템 타입 열거
enum class ItemType {
    Weapon,
    Armor,
    Consumable,
    Loot,
    Money
};

// 공통 데이터
struct ItemBase {
    int id;
    string name;
    int price;
};

// 무기
struct Weapon {
    ItemBase base;
    int attack;
};

// 방어구
struct Armor {
    ItemBase base;
    int defense;
};

// 소모품 (단순 회복형)
struct Consumable {
    ItemBase base;
    int hp;
};

// 전리품
struct Loot {
    ItemBase base;
    int amount;
};

// 화폐 (거래형)
struct Money {
    ItemBase base;
    int amount;
};

// DB 선언 (외부에서 정의)
extern map<int, Weapon> weaponDB;
extern map<int, Armor> armorDB;
extern map<int, Consumable> consumableDB;
extern map<int, Loot> LootDB;
extern map<int, Money> moneyDB;

// DB 초기화 함수
void initItemDB();
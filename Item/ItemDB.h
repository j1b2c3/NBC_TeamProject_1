#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

// 1. 아이템 데이터 구조 (기본값 설정으로 경고 해결)

enum class ItemType { Weapon, Armor, Consumable, Loot, Money };

struct ItemBase {
    int id = 0;
    string name = "";
    int price = 0;
    int sellprice = 0;
    bool canBuy = false;
};

struct Weapon { ItemBase base; int attack = 0; };
struct Armor { ItemBase base; int defense = 0; };
struct Consumable { ItemBase base; int hp = 0; };
struct Money { ItemBase base; int amount = 0; };

// 2. ItemManager 싱글톤 (데이터 중앙 관리)

class ItemManager {
private:
    ItemManager() {} // 생성자 은닉
    ItemManager(const ItemManager&) = delete;
    ItemManager& operator=(const ItemManager&) = delete;

public:
    static ItemManager& GetInstance() {
        static ItemManager instance;
        return instance;
    }

    // [데이터 저장소]
    map<int, Weapon> weaponDB;
    map<int, Armor> armorDB;
    map<int, Consumable> consumableDB;
    map<int, Money> moneyDB;

    // [데이터 채우기 함수 선언]
    void init();

    // [안전한 데이터 획득 함수 (Get)]
    // 클래스 내부에 있어야 멤버 변수(weaponDB 등)를 인식합니다.
    Weapon* GetWeapon(int id) {
        auto it = weaponDB.find(id);
        return (it != weaponDB.end()) ? &(it->second) : nullptr;
    }

    Armor* GetArmor(int id) {
        auto it = armorDB.find(id);
        return (it != armorDB.end()) ? &(it->second) : nullptr;
    }

    Consumable* GetConsumable(int id) {
        auto it = consumableDB.find(id);
        return (it != consumableDB.end()) ? &(it->second) : nullptr;
    }

    Money* GetMoney(int id) {
        auto it = moneyDB.find(id);
        return (it != moneyDB.end()) ? &(it->second) : nullptr;
    }
};

// 3. 하위 호환성 레이어 (다른 팀원들 코드 보호)
// 기존의 initItemDB() 호출을 싱글톤으로 연결

inline void initItemDB() {
    ItemManager::GetInstance().init();
}

// 기존의 weaponDB[id] 접근을 싱글톤 멤버로 연결 
inline auto& weaponDB = ItemManager::GetInstance().weaponDB;
inline auto& armorDB = ItemManager::GetInstance().armorDB;
inline auto& consumableDB = ItemManager::GetInstance().consumableDB;
inline auto& moneyDB = ItemManager::GetInstance().moneyDB;
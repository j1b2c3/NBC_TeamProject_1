#include "itemDB.h"

using namespace std;

// 실제 DB 정의
map<int, Weapon> weaponDB;
map<int, Armor> armorDB;
map<int, Consumable> consumableDB;
map<int, Loot> LootDB;
map<int, Money> moneyDB;

void initItemDB() {
    // 무기
    weaponDB[101] = { {101, "낡은 검", 100}, 10 };
    weaponDB[102] = { {102, "강철 검", 300}, 20 };

    // 방어구
    armorDB[201] = { {201, "가죽 갑옷", 150}, 5 };
    armorDB[202] = { {202, "철 갑옷", 400}, 15 };

    // 소모품
    consumableDB[301] = { {301, "체력 포션", 50}, 30 };
    consumableDB[302] = { {302, "대형 체력 포션", 120}, 100 };

    // 전리품
    LootDB[401] = { {401, "슬라임의 점액", 1}, 999 };

    // 화폐
    consumableDB[501] = { {501, "금화", 1}, 10000 };
}
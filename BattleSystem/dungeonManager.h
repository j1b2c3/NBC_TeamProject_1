#pragma once
#include "dungeonUI.h"
#include "BattleSystem.h"

#include "../Player/Player/Player.h"
#include "../Item/ItemDB.h"
#include "../Shop/Shop.h"
#include "../Player/Monster/MonsterDB.h"
#include "../Item/Inventory.h"
#include "../Item/Inventory_UI.h"

//switch case 용 필요 없어져서 제거 

class dungeonManager
{
    /*
private:
    static dungeonManager* Instance;
public:
	static dungeonManager* GetInstnace() // 싱글톤화
	{
		if (Instance == nullptr) // Instance 가 없으면
			Instance = new dungeonManager*;  // 새로 할당
		return Instance;// 할당되어있는 값 return ( 어차피 호출할 떄마다 투과됨)
	}
	*/

    bool b_isShopVisited;

    string getAreaName(int stageLevel)
    {
        switch (stageLevel)
        {
        case 1: return "버려진 초소";
        case 2: return "피의 황무지";
        case 3: return "잊혀진 묘지";
        case 4: return "그림자 숲";
        case 5: return "울부짖는 동굴";
        case 6: return "폭풍의 절벽";
        case 7: return "불타는 심연";
        case 8: return "용의 둥지";
        case 9: return "하늘의 제단";
        case 0: return "기만자의 방"; // 히든
        default: return "알 수 없는 구역";
        }
    }

    static constexpr int Last_Stage = 10; // 보스 등장 stage
    static constexpr int Shop_Stage = 3; // 3의 배율로 상점 등장
    bool b_LifeCheck; // 플레이어 생존 유무 확인
    bool b_Wincheck; // 플레이어 승리 유무 확인 변수 

    // Loot tempData;

    Shop Shop_;
    MonsterGenerator Mons_g;
    Monster* Monster_;

public:
    dungeonManager()
    {
    } // 생성자 
    ~dungeonManager()
    {
    }

    void Initialize(); // 시작 초기화
    void StartDungeon(Player* Player_); // player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >

    bool HiddenRand(); // 히든던전 등장 확률
    void EnterShop(Player* player_); // 상점 입장유무 

    void playerLifeCheck(Player* Player_);
};

// 요청사항 필요시 여기 아래 주석 입력 부탁드립니다..... 꾸엉...

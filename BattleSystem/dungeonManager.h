#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Player/Player/Player.h"
#include "BattleSystem.h"
#include "../Item/ItemDB.h"

class Player;

using namespace std;

struct BattleResult
{
	float Exp;
	int Gold;
	string item; // 예비용 
};


//switch case 용 필요 없어져서 제거 

static enum Stage_Category // 보상 관련 분할 
{
	None,
	Normal,
	Hidden,
	Boss
};
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
private:

	static const int Last_Stage = 10; // 보스 등장 stage
	static const int Shop_Stage = 5; // 5의 배율로 상점 등장
	int BattleCount; //BattleCount 현제 플레이어이의 Stage
	bool b_LifeCheck; // 플레이어 생존 유무 확인
	bool b_Wincheck; // 플레이어 승리 유무 확인 변수 
	Stage_Category Reward; //보상목록 

	Loot tempData;


public:
	dungeonManager() {}// 생성자 
	~dungeonManager() {}

	void Initialize(); // 시작 초기화
	bool setMonster(vector<Monster*> mons);
	void StartDungeon(Player* Player_,vector<Monster*> mons);// player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >

	void DugeonClear_Root(Player* player_); // 던전 클리어시 
	bool HiddenRand(); // 히든던전 등장 확률
	void EnterShop(Player* player_); // 상점 입장유무 

<<<<<<< HEAD
	void playerLifeCheck(Player* Player_);
	Monster* getrandmonster(vector<Monster*> mons);
=======
	void playerLifeCheck(Player* ply);
>>>>>>> Dev
	
};

// 요청사항 필요시 여기 아래 주석 입력 부탁드립니다..... 꾸엉...
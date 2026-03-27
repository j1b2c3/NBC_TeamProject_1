#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BattleResult
{
	float Exp;
	int Gold;
	string item; // 예비용 
};

static enum DungenMenu //switch case 용 
{
	Dungen_Enter = 1,
	Store_Enter = 2,
	Dungen_Exit = 0
};
static enum Stage_Category // 보상 관련 분할 
{
	Normal = 0,
	Hidden,
	Boss
};
template <typename Player>
class BattleManager
{
private:
	static BattleManager* Instance;
public:
	static BattleManager* GetInstnace() // 싱글톤화
	{
		if (Instance == nullptr) // Instance 가 없으면 
			Instance = new BattleManager*;  // 새로 할당
		return Instance;// 할당되어있는 값 return ( 어차피 호출할 떄마다 투과됨) 
	}
private:
	static const int Last_Stage = 10; // 보스 등장 stage
	static const int Shop_Stage = 5; // 5의 배율로 상점 등장
	int BattleCount; //BattleCount 현제 플레이어이의 Stage
	bool b_LifeCheck; // 플레이어 생존 유무 확인

	Player* Player_; // 있다고 가정함.
	Player* Monster_; // 있다고 가정함 
public:
	BattleManager() // 생성자 
	{
		Initialize(); // 일단은 생성과 동시에 초기화 하는 걸로 
	}
	~BattleManager() {}

	void Initialize();
	bool HiddenRand(); // 히든던전 등장 확률
	void startGame();

	void StartDungen(Player* ply, Player* mons);// player 데이터와 monster 데이터 받아서 실행 ( 몬스터 여러마리 넣을려먼 vector로 입력 받기 >
	void StartBattle();// Player 와 몬스터 전투 호출 
	void battleResult(); // 보상 확인
	void ClearRoot();


};
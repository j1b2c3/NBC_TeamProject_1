#pragma once
#include <vector>
#include <string>

#include "Player/Monster/monster.h"
#include "Player/Player.h"

// 내가 전투관련인데 BattleManager가 따로 있다니... 이름 충돌이 있어서 헷갈려요ㅠㅠ
class BattleSystem
{
private:
	// Singleton
	BattleSystem() {}
	BattleSystem(const BattleSystem& ref) {}
	BattleSystem& operator=(const BattleSystem& ref) {}
	~BattleSystem() {}
private:
	std::vector<Monster*> monsters;
	Player* player = nullptr;
public:
	static BattleSystem& getInstance()
	{
		static BattleSystem s;
		return s;
	}
	void Battle(Player* player, std::vector<Monster*> monsters);

	void CheckState();

	int SelectAction(std::vector<std::string> actions, int col); // 행동명, 한 줄당 액션표시 개수
};
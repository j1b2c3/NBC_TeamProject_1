#pragma once
#include <vector>
#include <string>

#include "../Player/Monster/monster.h"
#include "../Player/Player/Player_BattleTemp.h"

class BattleSystem
{
private:
	// Singleton
	BattleSystem() {}
	BattleSystem(const BattleSystem& ref) {}
	BattleSystem& operator=(const BattleSystem& ref) {}
	~BattleSystem() {}

	std::vector<std::string> GetMonsterNames();
	bool CheckState();
private:
	Player* player = nullptr;
	std::vector<Monster*> monsters;
	bool bProgress = true;
	bool bVictory = false;
public:
	static BattleSystem& getInstance()
	{
		static BattleSystem s;
		return s;
	}
	bool Battle(Player* _player, std::vector<Monster*> _monsters);	// 전투발생


	int SelectAction(std::vector<std::string> actions, int col); // 행동명, 한 줄당 액션표시 개수
};
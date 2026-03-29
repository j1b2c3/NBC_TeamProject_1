#pragma once
#include <vector>
#include <string>

#include "../Player/Monster/monster.h"
#include "../Player/Player/Player.h"
#include "../System/Windows.h"
#include "../System/Utility.h"
#include "Battle_UI.h"

class BattleSystem
{
private:
	// Singleton
	BattleSystem() {}
	BattleSystem(const BattleSystem& ref) {}
	BattleSystem& operator=(const BattleSystem& ref) {}
	~BattleSystem() {}

	void CheckState(Player& player, Monster& monster);
private:
	BattleLog log;
	bool bProgress = true;
	bool bVictory = false;
public:
	static BattleSystem& getInstance()
	{
		static BattleSystem s;
		return s;
	}
	bool Battle(Player& player, Monster& monster);	// 전투발생


	int SelectAction(std::vector<std::string> actions, int col); // 행동명, 한 줄당 액션표시 개수
};
#pragma once
#include <string>
#include "../Player/Player/Player.h"
#include "../Player/Monster/Monster.h"
#include "../System/Utility.h"
#include "../System/Windows.h"
using namespace std;
   
struct BattleLog
{
	string line_1 = "";
	string line_2 = "";
	string line_3 = "";
	void Clear()
	{
		line_1 = "";
		line_2 = "";
		line_3 = "";
	}
};
void displayBattle(class Player& const p, class Monster& const m, Vector2D& curPos, BattleLog log, string actionMsg = "계속하려면 아무 키를 눌러주세요...");
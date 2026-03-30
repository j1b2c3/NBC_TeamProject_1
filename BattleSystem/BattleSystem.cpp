#include <iostream>
#include <vector>
#include <algorithm>

#include "BattleSystem.h"

//#include <conio.h>

using namespace std;

bool BattleSystem::Battle(Player& player, Monster& monster)
{
	string msg = "전투가 시작되었다!";
	bProgress = true; // 전투가 진행중인가?
	bVictory = false; // 승리유무
	Vector2D curPos;
	while (true)
	{
		int choice;
		log.line_2 = "    [1] 공격           [2] 방어           [3] 아이템          [4] 도망";
		//플레이어 페이즈
		displayBattle(player, monster, curPos, log, "행동을 선택하세요 >> ");
		InputDigit(choice);
		choice--;
		log.Clear();
		switch (choice)
		{
		case 0:
			log.line_1.assign(monster.getName() + "에게 공격!");
			log.line_2.assign(to_string(player.Attack(monster)) + "의 피해를 입혔다! ");
			break;
		case 1:
			log.line_1.assign("방어를 시도했다!");
			break;
		case 2:
			log.line_1.assign("아이템을 사용했다!");
			break;
		case 3:
			log.line_1.assign("도주했다...");
			log.line_2.assign("전투가 종료되었다.");
			bProgress = false;
			break;
		default:
			log.line_3 = "                            잘못된 입력이다.";
			continue;
			break;
		}
		CheckState(player, monster);
		displayBattle(player, monster, curPos, log);
		Utility::PressAnyKey();
		if (!bProgress) break;

		// 몬스터 페이즈
		log.line_1.assign(monster.getName() + "의 공격!");
		log.line_2.assign(to_string(monster.Attack(player)) + "의 피해를 입었다! ");
		CheckState(player, monster);
		displayBattle(player, monster, curPos, log);
		Utility::PressAnyKey();
		if (!bProgress) break;
		log.Clear();
	}
	Windows::SetCursorPos(curPos);
	return bVictory;
}

// 전투상황 체크, 리타이어나 승패여부를 가른다.
void BattleSystem::CheckState(Player& player, Monster& monster)
{
	if (!bProgress)
		return;

	// 몬스터 체력체크
	if (monster.getCurHP() <= 0)
	{
		log.line_2.append(monster.getName() + "은(는) 쓰러졌다!");
	}

	// 플레이어 체력체크 (패배 체크)
	if (player.getCurHP() <= 0)
	{
		log.line_2.append(player.getNickname() + "은(는) 쓰러졌다!");
		log.line_3.assign("전투에서 패배했다...");
		bProgress = false;
		return;
	}

	// 승리 체크 (플레이어가 먼저 쓰러지면 패배, 승리)
	if (monster.getCurHP() <= 0)
	{
		log.line_3.assign("전투에서 승리했다!");
		bVictory = true;
		bProgress = false;
		return;
	}
}

// 취할 수 있는 행동(action)들을 출력한다. 한줄에 출력되는 action은 col갯수만큼.
int BattleSystem::SelectAction(vector<string> actions, int col)
{

	int choice = -1;
	int str_maxlen = 0;
	for (string a : actions)
	{
		if (str_maxlen < a.size())
			str_maxlen = a.size();
	}
	for (int i = 0; i < actions.size(); i++)
	{
		cout << (choice == i ? "▶ " : "　 ");
		cout << (i+1) << "." << actions[i];
		for (int j = actions[i].size(); j < str_maxlen; j++)
			cout << " ";

		if (not (i == actions.size() - 1 && i < col))
		{
			if ((i + 1) % col == 0)
				cout << '\n';
			else
				cout << " | ";
		}
	}

	cout << "\n\n입력: ";
	cin >> choice;

	return choice - 1;
}

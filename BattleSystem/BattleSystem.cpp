#include <iostream>
#include <vector>

#include "../System/Windows.h"
#include "BattleSystem.h"
#include "../System/Utility.h"
#include "Battle_UI.h"

//#include <conio.h>

using namespace std;

bool BattleSystem::Battle(Player& player, Monster& monster)
{
	string msg = "전투가 시작되었다!";
	bProgress = true; // 전투가 진행중인가?
	bVictory = false; // 승리유무
	while (true)
	{
		int choice;

		//플레이어 페이즈
		displayBattle(player, monster, msg);
		cout << "  행동을 선택하세요 >> " << '\n';
		cin >> choice;
		choice--;
		switch (choice)
		{
		case 0:
			cout << monster.GetName() << "에게 공격! ";
			cout << player.Attack(monster) << "의 피해를 입혔다!" << '\n';
			break;
		case 1:
			cout << "방어를 시도했다!" << '\n';
			break;
		case 2:
			cout << "아이템을 사용했다!" << '\n';
			break;
		case 3:
			cout << "도주했다..." << '\n';
			bProgress = false;
			break;
		default:
			break;
		}
		if (CheckState(player, monster)) break;

		// 몬스터 페이즈
		cout << monster.GetName() << "의 공격! ";
		cout << monster.Attack(player) << "의 피해를 입었다!" << '\n';
		if (CheckState(player, monster)) break;
	}
	return bVictory;
}

// 전투상황 체크, 리타이어나 승패여부를 가른다.
bool BattleSystem::CheckState(Player& player, Monster& monster)
{
	if (!bProgress)
		return true;

	// 몬스터 체력체크
	if (monster.GetCurHp() <= 0)
	{
		cout << monster.GetName() << "은(는) 쓰러졌다!" << endl;
	}

	// 플레이어 체력체크 (패배 체크)
	if (player.GetCurHp() <= 0)
	{
		cout << player.GetNickname() << "은(는) 쓰러졌다!" << endl;
		cout << "전투에서 패배했다..." << endl;
		bProgress = false;
		return true;
	}

	// 승리 체크 (플레이어가 먼저 쓰러지면 패배, 승리)
	if (monster.GetCurHp() <= 0)
	{
		cout << "전투에서 승리했다!" << endl;
		bVictory = true;
		bProgress = false;
		return true;
	}
	return false;
}

// 취할 수 있는 행동(action)들을 출력한다. 한줄에 출력되는 action은 col갯수만큼.
int BattleSystem::SelectAction(vector<string> actions, int col)
{

	//
	// ex) SelectAction({"공격", "행동", "아이템", "도망간다"}, 2}
	// ----------------------------------------------
	// ▶1.공격　　 | 　2.행동
	//   3.아이템　 | 　4.도망간다
	// ----------------------------------------------

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

	// 실시간 로그방식: 추후에 추가
	//Windows::CursorView(false);
	//while (true)
	//{
	//	int a = _getch();
	//	cout << a << endl;
	//}
	//Windows::CursorView(true);

	return choice - 1;
}

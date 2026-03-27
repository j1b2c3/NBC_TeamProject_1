#include <iostream>
#include <vector>

#include "../Windows.h"
#include "BattleSystem.h"

//#include <conio.h>

using namespace std;

vector<string> BattleSystem::GetMonsterNames()
{
	vector<string> v;
	for (Monster* m : monsters)
		v.push_back(m->getName());
	return v;
}

bool BattleSystem::Battle(Player* _player, vector<Monster*> _monsters)
{
	player = _player;
	monsters = _monsters;

	cout << "전투가 시작되었다!" << endl;

	bProgress = true; // 전투가 진행중인가?
	bVictory = false; // 승리유무
	while (true)
	{
		int choice;
		// 플레이어 페이즈
		cout << player->GetName() << ": (HP: " << player->GetHP() << "/" << player->GetHP_MAX() << ", ATK: " << player->GetATK() << ", DEF: " << player->GetDEF() << ")" << endl;
		cout << endl;
		for (Monster* m : monsters)
		{
			cout << m->getName() << ": (HP: " << m->getHP() << "/" << m->getHP_MAX() << ", ATK: " << m->getPower() << ", DEF: " << m->getDefence() << ")" << endl;
		}
		cout << endl;
		choice = SelectAction({"공격", "아이템", "도주"}, 2);

		switch (choice)
		{
		case 0:
			
			cout << "누구를 공격할까?" << endl;
			choice = SelectAction(GetMonsterNames(), 4);
			
			cout << monsters[choice]->getName() << "에게 공격! ";
			cout << player->Attack(monsters[choice]) << "의 피해를 입혔다!" << endl;
			
			break;
		case 1:
			cout << "아이템을 사용했다!" << endl;
			break;
		case 2:
			cout << "도주했다..." << endl;
			bProgress = false;
			break;
		}
		if (CheckState()) break;

		// 몬스터 페이즈
		choice = rand() % monsters.size();
		cout << monsters[choice]->getName() << "의 공격! ";
		cout << monsters[choice]->attack(player) << "의 피해를 입었다!" << endl;
		if (CheckState()) break;
	}
	return bVictory;
}

// 전투상황 체크, 리타이어나 승패여부를 가른다.
bool BattleSystem::CheckState()
{
	if (!bProgress)
		return true;

	// 몬스터 체력체크
	auto it = monsters.begin();
	while (it != monsters.end())
	{
		if ((*it)->getHP() <= 0)
		{
			cout << (*it)->getName() << "은(는) 쓰러졌다! (+" << (*it)->getExp() << " EXP, " << (*it)->getGold() << " G)" << endl;
			it = monsters.erase(it);
		}
		else
		{
			it++;
		}
	}

	// 플레이어 체력체크 (패배 체크)
	if (player->GetHP() <= 0)
	{
		cout << player->GetName() << "은(는) 쓰러졌다!" << endl;
		cout << "전투에서 패배했다..." << endl;
		bProgress = false;
		return true;
	}

	// 승리 체크
	if (monsters.empty())
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
				cout << endl;
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

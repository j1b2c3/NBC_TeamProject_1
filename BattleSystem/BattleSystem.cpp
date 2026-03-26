#include <iostream>
#include <vector>

#include "BattleSystem.h"

void BattleSystem::Battle(Player* player, std::vector<Monster*> monsters)
{
	this->player = player;
	this->monsters = monsters;

	std::cout << "전투가 시작되었다!" << std::endl;

	while (true)
	{
		int choice = 0;
		// 공격 페이즈
		std::cout << player->getNickname() << ": (HP: " << player->getHP() << "/" << player->getHPMax() << ", ATK: " << player->GetATK() << ", DEF: " << player->GetDEF() << ")" << std::endl;
		std::cout << std::endl;
		for (Monster* m : monsters)
		{
			std::cout << m->getName() << ": (HP: " << player->GetHP() << "/" << player->GetMax_HP() << ", ATK: " << player->GetATK() << ", DEF: " << player->GetDEF() << ")" << std::endl;
		}
		std::cout << std::endl;

	}
	for (Monster* m : monsters)
		delete m;
}

void BattleSystem::CheckState()
{
}

int BattleSystem::SelectAction(std::vector<std::string> actions, int col)
{
	// 취할 수 있는 행동(action)들을 출력한다. 한줄에 출력되는 action은 col갯수만큼.
	//
	// ex) SelectAction({"공격", "행동", "아이템", "도망간다"}, 2}
	// ----------------------------------------------
	// ▶1.공격　　 | 　2.행동
	//   3.아이템　 | 　4.도망간다
	// ----------------------------------------------
	int choice = 0;
	int str_maxlen = 0;
	for (std::string a : actions)
	{
		if (str_maxlen < a.size())
			str_maxlen = a.size();
	}
	for (int i = 0; i < actions.size(); i++)
	{
		//std::cout << (choice == i ? "▶" : "  ");
		//std::cout << (i + 1) << "." << actions[i];
		for (int j = actions[i].size(); j < str_maxlen; j++)
			std::cout << "  ";
		if (i == actions.size() - 1)
		{
			if ((i + 1) % col == 0)
				std::cout << std::endl;
			else
				std::cout << " | ";
		}
	}
	return 0;
}

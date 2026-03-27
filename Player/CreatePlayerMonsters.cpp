#include <string>
#include <iostream>
#include "Monster/Monster.h"
#include "Player/Player.h"
#include "Job/Warrior.h"
#include "Job/Thief.h"
#include "Job/Mage.h"
#include "Job/Archer.h"
using namespace std;

Player* CreatePlayer()
{
    string jobs[] = { "전사", "궁수", "도적", "마법사" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice)
    {
    case 1:
        player = new Warrior(nickname);
        break;
    case 2:
        player = new Archer(nickname);
        break;
    case 3:
        player = new Thief(nickname);
        break;
    case 4:
        player = new Mage(nickname);
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
    }
    return player;
}

void CreateMonsters()
{
    Monster* slime = new Monster("슬라임", 1, 10.0f, 10.0f, 2, 5, 0, 2, 10, 2, 4);
}
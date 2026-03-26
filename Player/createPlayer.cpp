#include <iostream>
#include <string>
#include "Monster/monster.h"
#include "Player/player.h"
#include "Job/warrior.h"
#include "Job/magician.h"
#include "Job/thief.h"
#include "Job/archer.h"

using namespace std;

string jobs[] = {"전사", "마법사", "도적", "궁수"};

Player* Job_choice(string nickname)
{
    cout << "<전직 시스템>" << '\n';
    cout << nickname << "님, 환영합니다!" << '\n';
    cout << "* 원하시는 직업을 선택해주세요." << '\n';

    for (int i = 0; i < 4; i++)
    {
        cout << (i + 1) << ". " << jobs[i] << '\n';
    }

    int job_choice;
    cout << "선택: ";
    cin >> job_choice;

    Player* newPlayer = nullptr;

    switch (job_choice)
    {
    case 1: newPlayer = new Warrior(nickname);
        break;
    case 2: newPlayer = new Magician(nickname);
        break;
    case 3: newPlayer = new Thief(nickname);
        break;
    case 4: newPlayer = new Archer(nickname);
        break;
    default:
        cout << "잘못된 입력입니다." << '\n';
        return nullptr;
    }
    return newPlayer;
}

static Player* createPlayer()
{
    string nickname;
    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    Player* p = Job_choice(nickname);
    if (p == nullptr) return nullptr;
    p->setNickname(nickname);

    return p;
}

static void battle(Player* player)
{
    string monsterNames[] = {"슬라임", "고블린", "오크", "트롤"};
    srand(time(nullptr));

    auto monster = new Monster(monsterNames[rand() % 4]);
    cout << "\n========== 전투 시작 ==========" << '\n';
    cout << "* " << monster->getName() << "이(가) 나타났습니다!" << '\n';

    while (true)
    {
        cout << "\n[전투] 1. 공격하기 / 2. 능력치 보기 / 3. 도망가기" << '\n';
        cout << "선택: ";
        int choice;
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 3)
        {
            cout << "* " << monster->getName() << "(으)로부터 도망쳤습니다!" << '\n';
            delete monster;
            return;
        }

        switch (choice)
        {
        case 1:
            player->attack(monster);

            if (monster->getHP() <= 0)
            {
                cout << "* " << monster->getName() << "을(를) 처치했습니다!" << '\n';
                delete monster;
                return;
            }

            monster->attack(player);

            if (player->getHP() <= 0)
            {
                cout << "* 당신은 쓰러졌습니다... 게임 오버." << '\n';
                delete monster;
                exit(0);
            }
            break;

        case 2:
            player->printPlayerStatus();
            break;
        default:
            cout << "잘못된 입력입니다." << '\n';
            break;
        }
    }
    delete monster;
}

static void menu(Player* player)
{
    while (true)
    {
        cout << "\n========== 마을 메뉴 ==========" << '\n';
        cout << "1. 몬스터 생성하기" << '\n';
        cout << "2. 내 능력치 보기" << '\n';
        cout << "3. 게임 종료" << '\n';
        cout << "선택: ";

        int choice;
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 3)
        {
            cout << "게임을 종료합니다." << '\n';
            break;
        }

        switch (choice)
        {
        case 1:
            battle(player);
            break;
        case 2:
            player->printPlayerStatus();
            break;
        default:
            cout << "잘못된 입력입니다." << '\n';
            break;
        }
    }
}

void playerCreate()
{
    Player* player = createPlayer();

    if (player != nullptr)
    {
        menu(player);
    }
    else
    {
        cout << "플레이어 생성에 실패했습니다." << '\n';
    }

    delete player;
}

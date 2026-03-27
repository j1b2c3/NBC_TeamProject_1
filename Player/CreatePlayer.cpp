#include <iomanip>
#include <string>
#include <iostream>

#include "Player/Player.h"
#include "Job/Warrior.h"
#include "Job/Thief.h"
#include "Job/Mage.h"
#include "Job/Archer.h"
using namespace std;

void displayMainUI()
{
    cout << "\n" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                           TEXT RPG - EPIC ADVENTURE                          |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|  ########  ########  ##     ##  ########     ########  ########    #######   |" << '\n';
    cout << "|     ##     ##         ##   ##      ##        ##     ## ##     ##  ##     ##  |" << '\n';
    cout << "|     ##     ######       ###        ##        ########  ########   ##         |" << '\n';
    cout << "|     ##     ##         ##   ##      ##        ##   ##   ##         ##   ####  |" << '\n';
    cout << "|     ##     ##        ##     ##     ##        ##    ##  ##         ##     ##  |" << '\n';
    cout << "|     ##     ########  ##     ##     ##        ##     ## ##          #######   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
}

void jobChoiceWarrior()
{
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|  전사는 높은 체력과 방어력을 갖는 대신 공격력이 약합니다.                    |" << '\n';
    cout << "|  정말 전사로 전직하시겠습니까?                                               |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                  [1] 예                          [2] 아니요                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "선택 : ";
}

void jobChoiceArcher()
{
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|  궁수는 높은 어쩌구 저쩌구                          |" << '\n';
    cout << "|  정말 궁수로 전직하시겠습니까?                                                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                  [1] 예                          [2] 아니요                   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "선택 : ";
}

void jobChoiceMage()
{
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|  마법사는 어쩌구                          |" << '\n';
    cout << "|  정말 마법사로 전직하시겠습니까?                                                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                  [1] 예                          [2] 아니요                   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "선택 : ";
}

void jobChoiceThief()
{
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|  도적은 어쩌구                          |" << '\n';
    cout << "|  정말 도적으로 전직하시겠습니까?                                                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                  [1] 예                          [2] 아니요                   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "선택 : ";
}

void selectJobUI(string nickname)
{
    string msg = nickname + "님, 원하시는 직업을 선택해 주세요";
    int remainingSpace = 74 - (int)msg.length();    
    
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|     <전직 시스템>                                                            |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     " << left << msg;
    cout << right << setw(remainingSpace) << "|" << '\n';
    cout << "|    [1] 전사           [2] 궁수             [3]  도적          [4] 마법사     |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
}

Player* createPlayer()
{
    string jobs[] = { "전사", "궁수", "도적", "마법사" };
    int job_choice = 0;
    int answer = 0;
    string nickname;

    Player* player = nullptr;

    cout << "\n" << '\n';
    displayMainUI();
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     TEXT RPG에 오신 것을 환영합니다.                                         |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     닉네임을 입력해 주세요!                                                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "닉네임 : ";
    cin >> nickname;
    
    while (true){
        selectJobUI(nickname);
        cout << "선택: ";
        if (!(cin >> job_choice)) {
            cin.clear(); cin.ignore(1000, '\n');
        }
    
        switch (job_choice)
        {
        case 1:
            jobChoiceWarrior();
            cin >> answer;
            if (answer == 1)
            {
                player = new Warrior(nickname);
                break;
            }
            else if (answer == 2)
                break;
            else
            {
                cout << "잘못 입력하셨습니다.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }
        case 2:
            jobChoiceArcher();
            cin >> answer;
            if (answer == 1)
            {
                player = new Archer(nickname);
                break;
            }
            else if (answer == 2)
                break;
            else
            {
                cout << "잘못 입력하셨습니다.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }

        case 3:
            jobChoiceThief();
            cin >> answer;
            if (answer == 1)
            {
                player = new Thief(nickname);
                break;
            }
            else if (answer == 2)
                break;
            else
            {
                cout << "잘못 입력하셨습니다.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }

        case 4:
            jobChoiceMage();
            cin >> answer;
            if (answer == 1)
            {
                player = new Mage(nickname);
                break;
            }
            else if (answer == 2)
                break;
            else
            {
                cout << "잘못 입력하셨습니다.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }
        default:
            cout << "잘못된 입력입니다." << '\n';
        }
        // 여기서 던전 시스템으로 연결, 인자 Player
        return player;
    }
}


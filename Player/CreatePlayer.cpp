#include <iomanip>
#include <string>
#include <iostream>

#include "../System/Windows.h"
#include "../System/util.h"
#include "Player/Player.h"
#include "Job/Warrior.h"
#include "Job/Thief.h"
#include "Job/Mage.h"
#include "Job/Archer.h"
using namespace std;

void displayMainUI()
{
    system("cls");
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

void displayConfirmJob(string jobName, string description)
{
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|  " << left << setw(76) << jobName + ": " + description << "|" << '\n';
    cout << "|  정말 " << left << setw(2) << jobName + "(으)로 전직하시겠습니까?                                          |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                  [1] 예                          [2] 아니요                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
}

void selectJobUI(string nickname)
{
    string msg = nickname + "님, 원하시는 직업을 선택해 주세요";
    int remainingSpace = 74 - static_cast<int>(msg.length());

    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|     <전직 시스템>                                                            |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     " << left << msg;
    cout << right << setw(remainingSpace) << "|" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|    [1] 전사           [2] 궁수             [3]  도적          [4] 마법사     |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
}


void choose_Job(string nickname, Player*& player)
{
    int job_choice = 0;
    int answer = 0;

    while (true)
    {
        selectJobUI(nickname);
        // "선택 >>" 위치로 이동 (줄 번호 확인 필요, 대략 19~20번 라인)
        Windows::SetCursorPos(15, 22);

        InputDigit(job_choice);
        //if (!(cin >> job_choice))
        //{
        //    cin.clear();
        //    cin.ignore(1000, '\n');
        //    continue;
        //}

        // 직업별 확인 창 로직
        string jobName = "";
        string desc = "";

        switch (job_choice)
        {
        case 1: jobName = "전사";
            desc = "높은 체력과 방어력을 갖습니다. 기본 능력치가 높습니다.";
            break;
        case 2: jobName = "궁수";
            desc = "방어 무시와 높은 회피를 갖습니다. 최소 5의 대미지를 줍니다.";
            break;
        case 3: jobName = "도적";
            desc = "높은 회피를 갖습니다. 50프로의 확률로 1.5배의 대미지를 줍니다.";
            break;
        case 4: jobName = "마법사";
            desc = "강력한 마법 공격력을 갖습니다. 10프로 확률로 2배의 대미지를 줍니다";
            break;
        default: continue;
        }

        displayConfirmJob(jobName, desc);
        Windows::SetCursorPos(15, 21);
        InputDigit(answer);

        if (answer == 1)
        {
            if (job_choice == 1) player = new Warrior(nickname);
            else if (job_choice == 2) player = new Archer(nickname);
            else if (job_choice == 3) player = new Thief(nickname);
            else if (job_choice == 4) player = new Mage(nickname);
            return;
        }
    }
}

Player* createPlayer()
{
    string jobs[] = {"전사", "궁수", "도적", "마법사"};
    string nickname;
    Player* player = nullptr;
    cout << "\n" << '\n';
    displayMainUI();
    cout << "|                                                                              |" << '\n';
    cout << "|     TEXT RPG에 오신 것을 환영합니다.                                         |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|     닉네임을 입력해 주세요!                                                  |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    닉네임 >>                                                                 | " << '\n';
    cout << "+==============================================================================+" << '\n';
    Windows::SetCursorPos(15, 20);
    cin >> nickname;
    
    choose_Job(nickname, player);
    return player;
}

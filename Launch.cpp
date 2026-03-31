#include <iostream>
#include <string>
#include <limits>
#include <ios>

#include "BattleSystem/dungeonManager.h"
#include "Player/CreatePlayer.h"
#include "System/Windows.h"

using namespace std;

// 메뉴 출력
void displayMenu()
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
    cout << "|                                                                              |" << '\n';
    cout << "|                              [1] 게임 시작                                   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|                              [2] 게임 종료                                   |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|    선택 >>                                                                   | " << '\n';
    cout << "+==============================================================================+" << '\n';
}

// 사용자 입력 받기
int getUserChoice()
{
    int choice;
    Windows::SetCursorPos(14, 20);
    InputDigit(choice);
    if (choice < 1 || choice > 2)
    {
        Windows::SetCursorPos(14, 20);
        cout << "숫자만 입력하세요!";
        Windows::SetCursorPos(14, 20); // 다시 입력 위치로 복귀
        cout << "         "; // 기존 잘못된 입력 지우기
        Windows::SetCursorPos(14, 20);
    }

    return choice;
}

int main()
{
    bool isRunning = true;
    dungeonManager dm;

    while (isRunning)
    {
        displayMenu();
        int choice = getUserChoice();

        switch (choice)
        {
        case 1:
            {
                system("cls");
                cout << "\n게임을 시작합니다..." << '\n';

                Player* myPlayer = createPlayer();

                if (myPlayer != nullptr)
                {
                    dm.StartDungeon(myPlayer);

                    delete myPlayer;
                    myPlayer = nullptr;
                }
            }
            break;

        case 2:
            system("cls");
            cout << "\n게임을 종료합니다. 감사합니다!" << '\n';
            isRunning = false;
            break;

        default:
            cout << "\n잘못된 입력입니다. 1 또는 2를 입력해주세요." << '\n';
            break;
        }
    }
    return 0;
}

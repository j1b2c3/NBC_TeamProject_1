#include <iostream>
#include <string>
#include <limits>
#include <ios>

#include "BattleSystem/dungeonManager.h"
#include "Player/CreatePlayer.h"
#include "Util/util.h"

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
    gotoxy(14, 20);

    while (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        gotoxy(14, 20);
        cout << "숫자(1, 2)만 입력하세요!";
        gotoxy(14, 20); // 다시 입력 위치로 복귀
        cout << "         "; // 기존 잘못된 입력 지우기
        gotoxy(14, 20);
    }

    cin.ignore(1000, '\n');

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
                    Monster* m = new Monster("sans", 1, 100, 1, 1, 5, 1, 2, 1, 2);
                    //dm.StartDungeon(myPlayer, { m });
                    BattleSystem::getInstance().Battle(*myPlayer, *m);
                    delete m;
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

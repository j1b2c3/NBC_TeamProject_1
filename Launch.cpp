#include <iostream>
#include <string>
#include <limits>
#include "Player/CreatePlayer.h"
using namespace std;

// 메뉴 출력
void displayMenu() {

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
    cout << "\n선택 >> ";
}

// 사용자 입력 받기
int getUserChoice() {
    int choice;
    cin >> choice;

    // 입력 버퍼 클리어
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

// 게임 시작 함수
void startGame() {
    cout << "\n게임을 시작합니다..." << '\n';
    //Todo : Game Start (캐릭터 생성)
}

//int main() {
//    bool isRunning = true;
//    
//    while (isRunning) {
//        displayMenu();
//        int choice = getUserChoice();
//
//        switch (choice) {
//            case 1:
//                startGame();
//                break;
//            case 2:
//                cout << "\n게임을 종료합니다. 감사합니다!" << endl;
//                isRunning = false;
//                break;
//            default:
//                cout << "\n잘못된 입력입니다. 1 또는 2를 입력해주세요." << endl;
//                break;
//        }
//    }
//
//    return 0;
//}


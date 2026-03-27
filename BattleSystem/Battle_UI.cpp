#include "Battle_UI.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 전투 UI를 출력하는 함수
// Player: 이름, HP/MaxHP, MP/MaxMP, Level
// Monster: 이름, HP/MaxHP, Level
void displayBattle(string playerName, int playerHP, int playerMaxHP,int playerLv,
                   string monsterName, int monsterHP, int monsterMaxHP, int monsterLv,
                   string battleMessage) {

    // HP, MP 바를 그리기 위한 비율 계산
    int playerHpBar = (playerMaxHP > 0) ? (playerHP * 20 / playerMaxHP) : 0;
    int monsterHpBar = (monsterMaxHP > 0) ? (monsterHP * 20 / monsterMaxHP) : 0;

    // --- 상단 테두리 ---
    cout << '\n' << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "|    #######         ##        ########    ########    ##          ########    |" << '\n';
    cout << "|    ##    ##       ####          ##          ##       ##          ##          |" << '\n';
    cout << "|    ##    ##      ##  ##         ##          ##       ##          ##          |" << '\n';
    cout << "|    #######      ########        ##          ##       ##          ######      |" << '\n';
    cout << "|    ##    ##     ##    ##        ##          ##       ##          ##          |" << '\n';
    cout << "|    ##    ##     ##    ##        ##          ##       ##          ##          |" << '\n';
    cout << "|    #######      ##    ##        ##          ##       ########    ########    |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // --- 몬스터 정보 ---
    cout << "|                                                                 [ MONSTER ]  |" << '\n';
    cout << "|  " << left << setw(12) << monsterName << " [Lv." << setw(2) << monsterLv << "] ";
    cout << "HP: [";
    for (int i = 0; i < 20; ++i) {
        if (i < monsterHpBar) cout << "#"; else cout << " ";
    }
    cout << "] (" << right << setw(4) << monsterHP << "/" << setw(4) << monsterMaxHP << " )                |" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    // --- 플레이어 정보 ---
    cout << "| [ PLAYER ]                                                                   |" << '\n';
    cout << "|  " << left << setw(12) << playerName << " [Lv." << setw(2) << playerLv << "] ";
    cout << "HP: [";
    for (int i = 0; i < 20; ++i) {
        if (i < playerHpBar) cout << "#"; else cout << " ";
    }
    cout << "] (" << right << setw(4) << playerHP << "/" << setw(4) << playerMaxHP << " )                |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 전투 로그 / 메시지 
    cout << "|    " << left << setw(73) << battleMessage << " |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 행동 메뉴
    cout << "|                                                                              |" << '\n';
    cout << "|    [1] 공격           [2] 방어           [3] 아이템         [4] 도망         |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';
    cout << "  행동을 선택하세요 >> " << '\n';
}
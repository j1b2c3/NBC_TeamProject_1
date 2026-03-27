#include "Battle_UI.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 전투 UI를 출력하는 함수
// Player: 이름, HP/MaxHP, MP/MaxMP, Level
// Monster: 이름, HP/MaxHP, Level
void displayBattle(Player& const p, Monster& const m, string battleMsg, string actionMsg) {

    // HP, MP 바를 그리기 위한 비율 계산
    int playerHpBar = (p.GetMaxHp() > 0) ? (p.GetCurHp() * 20 / p.GetMaxHp()) : 0;
    int monsterHpBar = (m.GetMaxHp() > 0) ? (m.GetCurHp() * 20 / m.GetMaxHp()) : 0;

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
    cout << "|  " << left << setw(12) << m.GetName() << " [Lv." << setw(2) << m.GetLevel() << "] ";
    cout << "HP: [";
    for (int i = 0; i < 20; ++i) {
        if (i < monsterHpBar) cout << "#"; else cout << " ";
    }
    cout << "] (" << right << setw(4) << m.GetCurHp() << "/" << setw(4) << m.GetMaxHp() << " )                |" << '\n';
    cout << "|  --------------------------------------------------------------------------  |" << '\n';

    // --- 플레이어 정보 ---
    cout << "| [ PLAYER ]                                                                   |" << '\n';
    cout << "|  " << left << setw(12) << p.GetNickname() << " [Lv." << setw(2) << p.GetLevel() << "] ";
    cout << "HP: [";
    for (int i = 0; i < 20; ++i) {
        if (i < playerHpBar) cout << "#"; else cout << " ";
    }
    cout << "] (" << right << setw(4) << p.GetCurHp() << "/" << setw(4) << p.GetMaxHp() << " )                |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 전투 로그 / 메세지 / 메뉴
    cout << "|                                                                              |" << '\n';
    cout << "|    [1] 공격           [2] 방어           [3] 아이템         [4] 도망         |" << '\n';
    cout << "|                                                                              |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 행동 메세지
    cout << "|    " << left << setw(73) << actionMsg << " |" << '\n';
    cout << "+==============================================================================+" << '\n';
}
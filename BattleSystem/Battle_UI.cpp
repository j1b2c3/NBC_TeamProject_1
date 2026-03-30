#include "Battle_UI.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 전투 UI를 출력하는 함수
// Player: 이름, HP/MaxHP, MP/MaxMP, Level
// Monster: 이름, HP/MaxHP, Level
void displayBattle(Player& const p, Monster& const m, Vector2D& curPos, BattleLog log, string actionMsg) {
    Vector2D inputCurPos;
    int n;

    // HP, MP 바를 그리기 위한 비율 계산
    int playerHpBar = (p.GetMaxHp() > 0) ? (p.GetCurHp() * 20 / p.GetMaxHp()) : 0;
    int monsterHpBar = (m.GetMaxHp() > 0) ? (m.GetCurHp() * 20 / m.GetMaxHp()) : 0;
    // 콘솔내역 비우기
    system("cls");

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
    cout << "|  " << left << setw(76) << log.line_1 << "|" << '\n';
    cout << "|  " << left << setw(76) << log.line_2 << "|" << '\n';
    cout << "|  " << left << setw(76) << log.line_3 << "|" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 행동 메세지
    cout << "|    " << left << actionMsg;
    // 현재 커서 위치를 가져온다
    inputCurPos = Windows::GetCursorPos();
    cout << right << setw(75 - actionMsg.length()) << " |" << '\n';
    cout << "+==============================================================================+" << '\n';

    // 입력후에 이동할 커서 위치를 미리 가져온다.
    curPos = Windows::GetCursorPos();

    // 이전에 저장한 커서 위치로 이동한다.
    Windows::SetCursorPos(inputCurPos);
}
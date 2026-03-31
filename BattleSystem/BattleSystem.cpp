#include <algorithm>
#include <iostream>
#include <vector>

#include "BattleSystem.h"

using namespace std;

bool BattleSystem::Battle(Player& player, Monster& monster)
{
    player.isBattle = true;
    string msg = "전투가 시작되었다!";
    bProgress = true; // 전투가 진행중인가?
    bVictory = false; // 승리유무
    log.Clear();
    while (true)
    {
        int choice;
        bool bPlayer_is_defence = false;
        string action_str = ""; // 특수 행동 시 기본행동과 동시에 출력할 문장
        int player_dmg;
        int monster_dmg;
        //플레이어 페이즈
        log.line_2.assign("    [1] 공격           [2] 방어           [3] 아이템          [4] 도망");
        displayBattle(player, monster, curPos, log, "행동을 선택하세요 >> ");
        InputDigit(choice);
        choice--;
        log.Clear();

        switch (choice)
        {
        case 0:
            log.line_1.assign(monster.getName() + "에게 공격!");
            player_dmg = player.Attack(monster, action_str);
            if (player_dmg > 0)
            {
                if (!action_str.empty()) action_str.append(" ");
                log.line_2.assign(action_str + to_string(player_dmg) + "의 피해를 입혔다! ");
            }
            else if (player_dmg == 0)
                log.line_2.assign(monster.getName() + "(이)가 공격을 방어했다!");
            else
                log.line_2.assign(monster.getName() + "(이)가 공격을 회피했다! ");
            break;
        case 1:
            log.line_1.assign("방어를 준비했다!");
            log.line_2.assign("이번 턴 동안 받는 피해가 감소합니다.");
            bPlayer_is_defence = true;
            break;
        case 2:
            if (!ChooseItem(player, monster)) continue;
            break;
        case 3:
            log.line_1.assign("도주했다...");
            log.line_2.assign("전투가 종료되었다.");
            bProgress = false;
            break;
        default:
            log.line_3 = "                            잘못된 입력입니다.";
            continue;
        }
        CheckState(player, monster);
        displayBattle(player, monster, curPos, log);
        util::PressEnterKey();
        if (!bProgress) break;

        // 몬스터 페이즈
        log.Clear();
        log.line_1.assign(monster.getName() + "의 공격!");
        monster_dmg = monster.attack(player, bPlayer_is_defence);
        if (monster_dmg > 0)
            log.line_2.assign(to_string(monster_dmg) + "의 피해를 입었다! ");
        else if (monster_dmg == 0)
            log.line_2.assign("방어에 성공했다! ");
        else
            log.line_2.assign("회피에 성공했다! ");
        CheckState(player, monster);
        displayBattle(player, monster, curPos, log);
        util::PressEnterKey();

        log.Clear();
        if (!bProgress) break;
    }
    Windows::SetCursorPos(curPos);
    player.isBattle = false;
    return bVictory;
}

// 전투상황 체크, 리타이어나 승패여부를 가른다.
void BattleSystem::CheckState(Player& player, Monster& monster)
{
    if (!bProgress)
        return;

    // 몬스터 체력체크
    if (monster.getCurHP() <= 0)
    {
        log.line_2.append(monster.getName() + "은(는) 쓰러졌다!");
    }

    // 플레이어 체력체크 (패배 체크)
    if (player.getCurHP() <= 0)
    {
        log.line_2.append(player.getNickname() + "은(는) 쓰러졌다!");
        log.line_3.assign("전투에서 패배했다...");
        bProgress = false;
        return;
    }

    // 승리 체크 (플레이어가 먼저 쓰러지면 패배, 승리)
    if (monster.getCurHP() <= 0)
    {
        int monster_gold;
        int monster_exp;
        log.line_3.assign("전투에서 승리했다!");
        monster.giveLoot(player, monster_exp, monster_gold);
        displayBattle(player, monster, curPos, log);
        util::PressEnterKey();
        log.Clear();
        int needExp;
        bool isLevelUp;
        player.addexp(monster_exp, needExp, isLevelUp);
        player.addGold(monster_gold);
        log.line_1.assign(to_string(monster_exp) + " EXP, " + to_string(monster_gold) + " G를 획득했다!");
        if (isLevelUp)
            log.line_2.append("(Level Up!) ");
        log.line_2.append(
            "Lv " + to_string(player.getLevel()) + " (" + to_string(player.getExp()) + " / " + to_string(needExp) +
            " EXP)");
        log.line_3.assign("현재 소지금: " + to_string(player.getGold()) + " Gold");
        bVictory = true;
        bProgress = false;
    }
}

bool BattleSystem::ChooseItem(Player& player, Monster& monster)
{
    vector<ItemInfo> items = player.getInventory()->getConsumables();
    int select;
    //int page = 0;
    log.line_1.assign("                        어떤 아이템을 사용할까?");
    //log.line_2.assign("                                                                            ");
    //log.line_2.assign("   [1]대형 체력 포션x1     [1]대형 체력 포션x1     [1]대형 체력 포션x1      ");
    log.line_2.assign("   ");
    for (int i = 0; i < 4 && i < items.size(); i++)
    {
        string tempStr;
        int len;
        tempStr.assign("[" + to_string(i + 1) + "]" + items[i].name + "x" + to_string(items[i].count));
        len = tempStr.length();
        log.line_2.append(tempStr);
        for (int j = len; j < 24; j++)
        {
            log.line_2.append(" ");
        }
    }
    log.line_3.assign("                             [0]돌아가기");
    displayBattle(player, monster, curPos, log, "아이템을 선택하세요 >> ");
    InputDigit(select);
    if (select == 0)
    {
        log.Clear();
        return false;
    }
    else if (select >= 1 && select <= items.size())
    {
        log.line_1.assign(items[select - 1].name + "을 사용했다!");
        log.line_2.assign(player.getInventory()->useConsumable(items[select - 1].id, player));
        log.line_3.assign("");
        return true;
    }
    log.line_3 = "                            잘못된 입력입니다.";
    return false;
}

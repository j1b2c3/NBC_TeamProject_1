#pragma once
#include <vector>
#include <string>

#include "../Player/Monster/monster.h"
#include "BattleSystem.h"
#include "../Player/Player/Player.h"
#include "../System/Windows.h"
#include "../System/util.h"
#include "Battle_UI.h"

class BattleSystem
{
    // Singleton
    BattleSystem()
    {
    }

    BattleSystem(const BattleSystem& ref)
    {
    }

    BattleSystem& operator=(const BattleSystem& ref)
    {
    }

    ~BattleSystem()
    {
    }

    void CheckState(Player& player, Monster& monster);
    bool ChooseItem(Player& player, Monster& monster);
    BattleLog log;
    bool bProgress = true;
    bool bVictory = false;
    Vector2D curPos;
public:
    static BattleSystem& getInstance()
    {
        static BattleSystem s;
        return s;
    }

    bool Battle(Player& player, Monster& monster, string EntryMessage); // 전투발생
};

#pragma once
#include "Monster.h"
#include "../Player/Player.h"
#include <iostream>

class MonsterGenerator
{
public:
    static Monster* Create(int stageLevel)
    {
        // 스테이지 레벨이나 난이도에 따라 9마리 중 하나를 반환
        switch (stageLevel)
        {
        case 1: return new Monster("고블린", 1, 50, 10, 2, 5, 20, 70, 50, 150);
        case 2: return new Monster("오크", 2, 80, 15, 5, 8, 30, 80, 150, 300);
        case 3: return new Monster("스켈레톤", 3, 120, 22, 8, 10, 40, 130, 250, 500);
        case 4: return new Monster("다크엘프", 4, 160, 30, 12, 15, 50, 140, 400, 750);
        case 5: return new Monster("트롤", 5, 320, 40, 48, 12, 60, 150, 600, 1100);
        case 6: return new Monster("와이번", 6, 380, 55, 65, 18, 80, 160, 850, 1600);
        case 7: return new Monster("데몬", 7, 500, 75, 85, 22, 90, 170, 1200, 2300);
        case 8: return new Monster("드래곤", 8, 950, 170, 130, 25, 100, 180, 1700, 3300);
        case 9: return new Monster("고대용", 9, 1750, 240, 170, 30, 100, 200, 2500, 5000);
        // 스테이지 0에서 히든 미믹
        default: return new Monster("미믹", 0, 1, 0, 0, 0, 1, 300, 1, 5000);
        }
    }
};

class FinalBoss : public Monster
{
    bool isCharging = false;

public:
    FinalBoss() : Monster("최종 보스", 10, 9999, 500, 300, 20, 1000, 1000, 1000, 1000)
    {
    }

    int attack(Player& player, bool is_defence) override;
};

class BossGenerator
{
public:
    static Monster* Create()
    {
        return new FinalBoss();
    }
};

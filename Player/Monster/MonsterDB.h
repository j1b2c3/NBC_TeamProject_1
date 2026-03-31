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
        case 1: return new Monster("고블린", 1, 50, 10, 2, 5, 100, 100, 50, 150);
        case 2: return new Monster("오크", 2, 80, 15, 5, 8, 100, 100, 150, 300);
        case 3: return new Monster("스켈레톤", 3, 120, 22, 8, 10, 100, 100, 250, 500);
        case 4: return new Monster("다크엘프", 4, 160, 30, 12, 15, 100, 100, 400, 750);
        case 5: return new Monster("트롤", 5, 220, 40, 18, 12, 100, 100, 600, 1100);
        case 6: return new Monster("와이번", 6, 300, 55, 25, 18, 100, 100, 850, 1600);
        case 7: return new Monster("데몬", 7, 400, 75, 35, 22, 100, 100, 1200, 2300);
        case 8: return new Monster("드래곤", 8, 550, 100, 50, 25, 100, 100, 1700, 3300);
        case 9: return new Monster("고대용", 9, 750, 140, 70, 30, 100, 100, 2500, 5000);
        // 스테이지 0에서 히든 미믹
        default: return new Monster("미믹", 0, 1, 0, 0, 0, 50, 500, 30, 500);
        }
    }
};

class FinalBoss : public Monster
{
    private:
    bool isCharging = false;
    
public:
    FinalBoss() : Monster("최종 보스", 10, 1000, 100, 100, 10, 1000, 1000, 1000, 1000) {}      
    
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

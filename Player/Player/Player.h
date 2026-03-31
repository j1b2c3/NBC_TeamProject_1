#pragma once
#include "../Monster/Monster.h"
#include "../../Item/Inventory.h"
#include <string>
using namespace std;

class Inventory;

class Player
{
protected:
    string nickname;
    string jobname;
    int level;
    int exp;
    int maxHP;
    int curHP;
    int atk;
    int def;
    int dodge;
    int gold;

    Inventory* inventory;

private:
    bool isDodged(int dodge);

protected:
    int calculateDamage(int atk, int def);

public:
    Player(string nickname);
    ~Player();

    Inventory* getInventory() { return inventory; }

    // monster: 대상 몬스터, action_str: 특수한 행동 시 추가 출력한 문자열
    virtual int Attack(Monster& monster, string& action_str) = 0;
    virtual void level_Up() = 0;
    int TakeDamage(int damage);
    void addexp(int gainedExp);
    void subExp(int lostExp);
    void addGold(int gold);
    void subGold(int gold);

    string getNickname();
    string getJobName();
    int getLevel();
    int getExp();
    int getMaxHP();
    int getCurHP();
    int getAtk();
    int getDef();
    int getDodge();
    int getGold();

    void setNickname(string nickname);
    void setLevel(int level);
    void setExp(int exp);
    void setMaxHP(int maxHP);
    void setCurHP(int curHP);
    void setAtk(int atk);
    void setDef(int def);
    void setDodge(int dodge);
    void setGold(int gold);
};


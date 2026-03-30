#pragma once
#include "../Monster/Monster.h"
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

    virtual int Attack(Monster& monster) = 0;
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

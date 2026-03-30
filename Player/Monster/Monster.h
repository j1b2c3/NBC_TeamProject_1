#pragma once
#include <vector>
#include <string>

class Player;

class Monster
{
protected:
    std::string name;
    int level;
    int maxHP;
    int curHP;
    int atk;
    int def;
    int dodge;
    int maxExp;
    int minExp;
    int maxGold;
    int minGold;
    //std::vector<item> items;
private:
    bool isDodged(int dodge);

public:
    Monster(
        std::string name,
        int level,
        int Hp,
        int atk,
        int def,
        int dodge,
        int minExp,
        int maxExp,
        int minGold,
        int maxGold //vector<item> items;
    );
    virtual ~Monster() = default;

    virtual int attack(Player& player);

    void TakeDamage(int damage, bool canDodge);
    void giveLoot(Player& player);

    int calculateDamage(int atk, int def);
    std::string getName();
    int getLevel();
    int getMaxHP();
    int getCurHP();
    int getAtk();
    int getDef();
    int getDodge();
    int getMaxExp();
    int getMinExp();
    int getMaxGold();
    int getMinGold();
};

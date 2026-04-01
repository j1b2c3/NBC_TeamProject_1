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
    std::string specialMessage; // 특별한 메세지를 입력하면 해당 턴에는 공격하지 않고 대신 해당 메세지를 출력한다.
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

    virtual int attack(Player& player, bool is_defence, std::string& action_str);

    int TakeDamage(int damage, bool canDodge);
    void giveLoot(Player& player, int& outEXP, int& outGOLD);

    int calculateDamage(int atk, int def, bool is_defence);
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
    std::string getSpecialMessage();
    void ClearSpecialMessage();
};

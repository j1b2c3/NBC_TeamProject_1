#pragma once
#include <vector>
#include <string>

class Player;

class Monster
{
protected:
	std::string name;
	int level;
	int maxHp;
	int curHp;
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
    int calculateDamage(int atk, int def);
    
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
			int maxGold		//vector<item> items;
	);
	virtual ~Monster();

	int Attack(Player& player);

	int TakeDamage(size_t damage, bool canDodge);
	void giveLoot(Player& player);

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

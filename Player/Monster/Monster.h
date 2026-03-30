<<<<<<< HEAD
#pragma once
#include <vector>
#include <string>

class Player;

class Monster
{
protected:
    std::string name;
    int level;
    float maxHp;
    float curHp;
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
        float maxHp,
        float curHp,
        int atk,
        int def,
        int dodge,
        int minExp,
        int maxExp,
        int minGold,
        int maxGold
        //vector<item> items;
    );

    void Attack(Player& player);

    void TakeDamage(int damage, bool canDodge);
    void giveLoot(Player& player);

    std::string GetName();
    int GetLevel();
    float GetMaxHp();
    float GetCurHp();
    int GetAtk();
    int GetDef();
    int GetDodge();
    int GetMaxExp();
    int GetMinExp();
    int GetMaxGold();
    int GetMinGold();
};
=======
﻿#pragma once
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
		int maxGold
		//vector<item> items;
	);

	int Attack(Player& player);

	int TakeDamage(size_t damage, bool canDodge);
	void giveLoot(Player& player);

	std::string GetName();
	int GetLevel();
	int GetMaxHp();
	int GetCurHp();
	int GetAtk();
	int GetDef();
	int GetDodge();
	int GetMaxExp();
	int GetMinExp();
	int GetMaxGold();
	int GetMinGold();
};
>>>>>>> Dev

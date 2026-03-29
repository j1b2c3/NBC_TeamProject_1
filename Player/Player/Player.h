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
	int maxHp;
	int curHp;
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
	
	Inventory* getInventory() {return inventory;}

	virtual int Attack(Monster& monster) = 0;
	int TakeDamage(int damage);
	void AddExp(int gainedExp);
	void SubExp(int lostExp);
	void AddGold(int gold);
	void SubGold(int gold);

	string GetNickname();
	string GetJobName();
	int GetLevel();
	int GetExp();
	int GetMaxHp();
	int GetCurHp();
	int GetAtk();
	int GetDef();
	int GetDodge();
	int GetGold();

	void SetNickname(string nickname);
	void SetLevel(int level);
	void SetExp(int exp);
	void SetMaxHp(float maxHp);
	void SetCurHp(float curHp);
	void SetAtk(int atk);
	void SetDef(int def);
	void SetDodge(int dodge);
	void SetGold(int gold);
};


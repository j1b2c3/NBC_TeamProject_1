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
	float maxHp;
	float curHp;
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
	
	
	virtual void Attack(Monster& monster) = 0;
	void TakeDamage(int damage);
	void AddExp(int gainedExp);
	void SubExp(int lostExp);
	void AddGold(int gold);
	void SubGold(int gold);

	string getNickname();
	string getJobName();
	int getLevel();
	int getExp();
	float getMaxHp();
	float getCurHp();
	int getAtk();
	int getDef();
	int getDodge();
	int getGold();
	
	void setNickname(string nickname);
	void setLevel(int level);
	void setExp(int exp);
	void setMaxHp(float maxHp);
	void setCurHp(float curHp);
	void setAtk(int atk);
	void setDef(int def);
	void setDodge(int dodge);
	void setGold(int gold);
};


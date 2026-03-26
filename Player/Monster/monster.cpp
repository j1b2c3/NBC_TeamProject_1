#include "monster.h"
#include "..//Player/Player_BattleTemp.h"
#include <iostream>
using namespace std;

Monster::Monster(string name) {
	this->name = name;
	HP = HP_MAX = 100;
	power = 30;
	defence = 10;
	speed = 10;
	gold = 10;
	exp = 5;
}

int Monster::attack(Player* player) {
	int damage = power - player->GetDEF();
	if (damage <= 0) 
		damage = 1;
	player->SetHP(player->GetHP() - damage);
	return damage;
}

void Monster::setName(string name) {
	this->name = name;
}

void Monster::setHP(int value) {
	HP = value;
	if (HP < 0)
		HP = 0;
	else if (HP > HP_MAX)
		HP = HP_MAX;
}

void Monster::setPower(int value) {
	power = value;
}

void Monster::setDefence(int value) {
	defence = value;
}

void Monster::setSpeed(int value) {
	speed = value;
}

string Monster::getName() const {
	return name;
}

int Monster::getHP() const {
	return HP;
}

int Monster::getHP_MAX() const
{
	return HP_MAX;
}

int Monster::getPower() const {
	return power;
}

int Monster::getDefence() const {
	return defence;
}

int Monster::getSpeed() const {
	return speed;
}

int Monster::getGold() const
{
	return gold;
}

int Monster::getExp() const
{
	return exp;
}


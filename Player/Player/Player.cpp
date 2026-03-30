#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string nickname)
{
	level = 1;
	exp = 0;
	maxHP = curHP = 100;
	atk = 5;
	def = 10;
	dodge = 5;
	gold = 0;
	this->nickname = nickname;
}

Player::~Player()
{
	
}

bool Player::isDodged(int dodge)
{
	return rand() % 100 < dodge;
}

int Player::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	float damage = atk * (1.0f - reduction);

	if (damage <= 0) damage = 1;

	return static_cast<int>(damage);
}

int Player::TakeDamage(int damage)
{
	if (isDodged(dodge))
		return -1;

	curHP -= damage;
	if (curHP < 0)
		curHP = 0;
	return damage;
}

void Player::addexp(int gainedExp)
{
    int needExp = 100;

    for (int i = 1; i < level; i++)
    {
        needExp *= 2;
    }

    exp += gainedExp;

    while (exp >= needExp)
    {
        exp -= needExp;
        level++;
        needExp *= 2;
    }

    cout << "레벨: " << level << '\n';
    cout << "남은 경험치: " << exp << " / " << needExp << '\n';
}

int Player::Attack(Monster& monster)
{
	int damage = calculateDamage(atk, monster.getDef());
	return damage;
}

void Player::subExp(int lostExp)
{
	exp -= lostExp;
	if (exp < 0) exp = 0;
}

void Player::addGold(int gold)
{
	this->gold += gold;
}

void Player::subGold(int gold)
{
	this->gold -= gold;
}

string Player::getNickname()
{
	return nickname;
}

string Player::getJobName()
{
	return jobname;
}

int Player::getLevel()
{
	return level;
}

int Player::getExp()
{
	return exp;
}

int Player::getMaxHP()
{
	return maxHP;
}

int Player::getCurHP()
{
	return curHP;
}

int Player::getAtk()
{
	return atk;
}

int Player::getDef()
{
	return def;
}

int Player::getDodge()
{
	return dodge;
}

int Player::getGold()
{
	return gold;
}

void Player::setNickname(string nickname)
{
	this->nickname = nickname;
}

void Player::setLevel(int level)
{
	this->level = level;
}

void Player::setExp(int exp)
{
	this->exp = exp;
}

void Player::setMaxHP(int maxHP)
{
	this->maxHP = maxHP;
}

void Player::setCurHP(int curHP)
{
	this->curHP = curHP;
}

void Player::setAtk(int atk)
{
	this->atk = atk;
}

void Player::getDef(int def)
{
	this->def = def;
}

void Player::setdodge(int dodge)
{
	this->dodge = dodge;
}

void Player::setgold(int gold)
{
	this->gold = gold;
}

#include "Player.h"
#include <algorithm>
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
    inventory = new Inventory();
}

Player::~Player()
{
    delete inventory;
}

bool Player::isDodged(int dodge)
{
    return rand() % 100 < dodge;
}

int Player::calculateDamage(int atk, int def)
{
	float reduction = def / 100.0f;
	int damage = static_cast<int>((float)atk * (1.0f - reduction));

	if (damage <= 0) damage = 1;

	return damage;
}

int Player::TakeDamage(int damage)
{
    if (isDodged(dodge))
        return -1;

    curHP -= damage;
    curHP = std::max(curHP, 0);
    return damage;
}

void Player::addexp(int gainedExp)
{
    int needExp = 100;
        exp += gainedExp;

    while (exp >= needExp)
    {
        exp -= needExp;
        level_Up();
    }

    cout << "레벨: " << level << '\n';
    cout << "남은 경험치: " << exp << " / " << needExp << '\n';
}

int Player::Attack(Monster& monster, string& action_str)
{
	int damage = calculateDamage(atk, monster.getDef());
	action_str = "";
	return monster.TakeDamage(damage, true);
}

void Player::level_Up()
{
    level++;
    maxHP += 10;
    curHP += 10;
    atk += 1;
    def += 1;
    dodge += 1;
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

void Player::setDef(int def)
{
    this->def = def;
}

void Player::setDodge(int dodge)
{
    this->dodge = dodge;
}

void Player::setGold(int gold)
{
    this->gold = gold;
}

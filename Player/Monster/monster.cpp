#include "monster.h"
#include "..//Player/player.h"
#include <iostream>
using namespace std;

Monster::Monster(string name) {
	this->name = name;
	this->HP = 100;
	this->power = 30;
	this->defence = 10;
	this->speed = 10;
}

void Monster::attack(Player* player) {
	int damage = power - player->getDefence();
	if (damage <= 0) damage = 1;
	cout << "* " << name << "이(가) " << player->getNickname() << "에게 " << damage << "의 데미지를 입혔습니다." << '\n';
	int newHP = player->getHP() - damage;
	player->setHP(newHP);
	if (newHP > 0) {
		cout << "* " << player->getNickname() << "의 남은 HP: " << newHP << '\n';
	}
	else {
		cout << "* " << player->getNickname() << "이(가) 쓰러졌습니다." << '\n';
	}
}


void Monster::setName(string name) {
	this->name = name;
}

void Monster::setHP(int HP) {
	this->HP = HP;
}

void Monster::setPower(int power) {
	this->power = power;
}

void Monster::setDefence(int defence) {
	this->defence = defence;
}

void Monster::setSpeed(int speed) {
	this->speed = speed;
}

string Monster::getName() {
	return name;
}

int Monster::getHP() {
	return HP;
}

int Monster::getPower() {
	return power;
}

int Monster::getDefence() {
	return defence;
}

int Monster::getSpeed() {
	return speed;
}


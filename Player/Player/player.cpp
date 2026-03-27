#include "player.h"
#include <iostream>
using namespace std;

Player::Player(const string& nickname) 
	: nickname(nickname), level(1) {}
	
void Player::printPlayerStatus() {
	cout << "------------------------------------" << '\n';
	cout << "* 현재 능력치" << '\n';
	cout << "닉네임: " << nickname << '\n';
	cout << "Lv. " << level << '\n';
	cout << "HP: " << HP << '\n';
	cout << "MP: " << MP << '\n';
	cout << "공격력: " << power << '\n';
	cout << "방어력: " << defence << '\n';
	cout << "정확도: " << accuracy << '\n';
	cout << "속도: " << speed << '\n';
	cout << "------------------------------------" << '\n';
}

void Player::setNickname(string nickname)
{
	this->nickname = nickname;
}

void Player::setHP(int HP) {
	this->HP = HP;
}

void Player::setMP(int MP) {
	this->MP = MP;
}

void Player::setPower(int power) {
	this->power = power;
}

void Player::setDefence(int defence) {
	this->defence = defence;
}

void Player::setAccuracy(int accuracy) {
	this->accuracy = accuracy;
}

void Player::setSpeed(int speed) {
	this->speed = speed;
}

string Player::getJobName() {
	return job_name;
}

string Player::getNickname() {
	return nickname;
}

int Player::getLevel() {
	return level;
}

int Player::getHP() {
	return HP;
}

int Player::getMaxHP()
{
	return maxHp;
}

int Player::getMP() {
	return MP;
}

int Player::getPower() {
	return power;
}

int Player::getDefence() {
	return defence;
}

int Player::getAccuracy() {
	return accuracy;
}

int Player::getSpeed() {
	return speed;
}



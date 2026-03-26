#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string nickname) {
	this->nickname = nickname;
	level = 1;
}

void Player::printPlayerStatus() {
	cout << "------------------------------------" << endl;
	cout << "* 현재 능력치" << endl;
	cout << "닉네임: " << nickname << endl;
	cout << "Lv. " << level << endl;
	cout << "HP: " << HP << endl;
	cout << "MP: " << MP << endl;
	cout << "공격력: " << power << endl;
	cout << "방어력: " << defence << endl;
	cout << "정확도: " << accuracy << endl;
	cout << "속도: " << speed << endl;
	cout << "------------------------------------" << endl;
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



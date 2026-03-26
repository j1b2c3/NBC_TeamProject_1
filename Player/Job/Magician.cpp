#include "Magician.h"
#include "../Monster/monster.h"
#include <iostream>

using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "마법사";
    cout << "* 마법사로 전직하였습니다." << endl;
	HP = 60;
	MP = 70;
	power = 130;
	defence = 8;
	accuracy = 15;
	speed = 5;
}

void Magician::attack() {
    cout << "* 마법으로 공격했다" << endl;
}

void Magician::attack(Monster* monster) {
	attack();
	int damage = power/5 - monster->getDefence();
	if (damage <= 0) damage = 1;
	cout << "* " << monster->getName() << "에게 " << damage << "의 데미지를 5번 입혔습니다." << endl;
	int newHP = monster->getHP() - damage * 5;
	monster->setHP(newHP);
	if (newHP > 0) {
		cout << "* " << monster->getName() << "의 남은 HP: " << newHP << endl;
	}
	else {
		cout << "* " << monster->getName() << "이(가) 쓰러졌습니다." << endl;
	}
}
#include "Thief.h"
#include "../Monster/monster.h"
#include <iostream>

using namespace std;

Thief::Thief(string nickname) : Player(nickname) {
    job_name = "도적";
    cout << "* 도적으로 전직하였습니다." << endl;
    HP = 60;
	MP = 30;
	power = 20;
	defence = 5;
	accuracy = 20;
	speed = 20;
}

void Thief::attack() {
    cout << "* 단검을 휘두른다" << endl;
}


void Thief::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	if (damage <= 0) damage = 1;
	int criticalChance = rand() % 100;
	if (criticalChance > 90) {
		damage *= 2;
		cout << "* 크리티컬 히트! ";
	}
	cout << "* " << monster->getName() << "에게 " << damage << "의 데미지를 입혔습니다." << endl;
	int newHP = monster->getHP() - damage;
	monster->setHP(newHP);
	if (newHP > 0) {
		cout << "* " << monster->getName() << "의 남은 HP: " << newHP << endl;
	}
	else {
		cout << "* " << monster->getName() << "이(가) 쓰러졌습니다." << endl;
	}
}
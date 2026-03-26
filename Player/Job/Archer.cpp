#include "Archer.h"
#include "monster.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) {
    job_name = "궁수";
    cout << "* 궁수로 전직하였습니다." << endl;
	HP = 50;
	MP = 40;
	power = 30;
	defence = 5;
	accuracy = 30;
	speed = 15;
}

void Archer::attack() {
    cout << "* 활을 쏘았다." << endl;
}

void Archer::attack(Monster* monster)  {
	attack();
	int damage = power/2 - monster->getDefence();
	if (damage <= 0) damage = 1;
	cout << "* " << monster->getName() << "에게 " << damage << "의 데미지를 2번 입혔습니다." << endl;
	int newHP = monster->getHP() - damage * 2;
	monster->setHP(newHP);
	if (newHP > 0) {
		cout << "* " << monster->getName() << "의 남은 HP: " << newHP << endl;
	}
	else {
		cout << "* " << monster->getName() << "이(가) 쓰러졌습니다." << endl;
	}
}
#include "warrior.h"
#include "../Monster/monster.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "전사";
    cout << "* 전사로 전직하였습니다." << endl;
	HP = 100;
	MP = 30;
	power = 30;
	defence = 25;
	accuracy = 10;
	speed = 10;
}

void Warrior::attack() {
    cout << "* 장검을 휘두른다" << endl;
}

void Warrior::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	int DNChance = rand() % 100;
	if (DNChance > 80) {
		damage = power;
		cout << "* 방어력 무시! ";
	}
	if (damage <= 0) damage = 1;
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
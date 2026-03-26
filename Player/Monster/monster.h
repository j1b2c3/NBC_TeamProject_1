#pragma once
#include <string>
using namespace std;

class Player;

class Monster {
public:
    Monster(string name);
    void attack(Player* player);

    string getName();
    int getHP();
    int getPower();
    int getDefence();
    int getSpeed();

    // 몬스터의 속성값을 정의하는 set 함수
    void setName(string name);
    void setHP(int HP);
    void setPower(int power);
    void setDefence(int defence);
    void setSpeed(int speed);

protected:
    string name; // 몬스터의 이름
    int HP; // 몬스터의 HP
    int power; // 몬스터의 공격력
    int defence; // 몬스터의 방어력
    int speed; // 몬스터의 스피드
};
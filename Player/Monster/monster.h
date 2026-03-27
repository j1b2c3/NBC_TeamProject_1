#pragma once
#include <string>
using namespace std;

class Player;

class Monster {
public:
    Monster(string name);
    int attack(Player* player);

    string getName() const;
    int getHP() const;
    int getHP_MAX() const;
    int getPower() const;
    int getDefence() const;
    int getSpeed() const;

    int getGold() const;
    int getExp() const;

    // 몬스터의 속성값을 정의하는 set 함수
    void setName(string name);
    void setHP(int value);
    void setPower(int value);
    void setDefence(int value);
    void setSpeed(int value);

protected:
    string name; // 몬스터의 이름
    int HP; // 몬스터의 HP
    int HP_MAX; // 몬스터의 HP
    int power; // 몬스터의 공격력
    int defence; // 몬스터의 방어력
    int speed; // 몬스터의 스피드

    int gold;   // 몬스터의 골드
    int exp;    // 몬스터의 경험치
};
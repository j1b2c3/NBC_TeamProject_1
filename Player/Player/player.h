#pragma once
#include <string>
using namespace std;
class Monster;

class Player {
public:
    virtual void attack() = 0;
	virtual void attack(Monster* monster) = 0;
    Player(const string& nickname);
    void printPlayerStatus();

    // getter 함수
    string getJobName();
    string getNickname();
    int getLevel();
    int getHP();
    int getMaxHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수
    void setNickname(string nickname);
    void setHP(int HP);
    void setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

protected:
    string job_name;
    string nickname;
    int level;
    int maxHp;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};
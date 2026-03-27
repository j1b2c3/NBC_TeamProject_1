#pragma once
#include <string>

using namespace std;

class Monster;

class Player {
public:
    virtual void attack() = 0;
	virtual void attack(Monster* monster) = 0;
    Player(const std::string& nickname);
    void printPlayerStatus();

    // getter 함수
    std::string getJobName();
    std::string getNickname();
    int getLevel();
    int getHP();
    int getMaxHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();
    int getGold();

    // setter 함수
    void setNickname(std::string nickname);
    void setHP(int HP);
    void setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);
    void setGold(int g);

protected:
    std::string job_name;
    std::string nickname;
    int level;
    int maxHp;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
    int gold = 0;
};
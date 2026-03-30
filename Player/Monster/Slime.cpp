#include "Slime.h"
#include "Monster.h"
#include <iostream>

// 부모 생성자 호출 (이름, 레벨, HP, 공격력, 방어력, 회피율, 경험치범위, 골드범위 순서)
Slime::Slime(std::string name, int level)
    : Monster(name, level, 50, 5, 2, 5, 10, 20, 5, 15) {}

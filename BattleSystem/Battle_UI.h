#pragma once
#include <string>
#include "../Player/Player/Player.h"
#include "../Player/Monster/Monster.h"
using namespace std;
   
void displayBattle(class Player& const p, class Monster& const m, string battleMsg = "", string actionMsg = "계속하려면 아무키를 눌러주세요.");
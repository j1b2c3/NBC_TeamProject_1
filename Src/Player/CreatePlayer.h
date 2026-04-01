#pragma once

#include "Player/Player.h"
#include <string>

Player* createPlayer();

void displayMainUI();
void displayJobMenu();
void choose_Job(string nickname, Player*& player);
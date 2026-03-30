#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
    Slime(std::string name = "슬라임", int level = 1);

    virtual ~Slime() override = default;
};
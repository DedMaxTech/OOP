#pragma once
#include "class.h"

class Army {
public:
    Creature personal_guard ;
    Creature& police;

    Army(Creature& police);
    ~Army();
};
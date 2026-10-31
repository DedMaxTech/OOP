#pragma once
#include "army.h"


Army::Army(Creature& police) : 
    police(police), 
    personal_guard(Creature("personal_guard","Guard",100)) {};

Army::~Army() {
    // delete this->personal_guard;
}
#include "doctor.h"
#include "class.h"
#include <iostream>

void Doctor::heal(Creature& c, int amount) {
    c.health = c.health + amount;
    std::cout << "[Doctor] Creature " << c.name << " healed by " << amount << std::endl;
}

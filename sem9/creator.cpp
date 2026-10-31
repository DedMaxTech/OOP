#include "creator.h"
#include "class.h"
#include <iostream>

void set_creature_name(Creature& creature, const std::string& new_name) {
    creature.name = new_name.empty() ? "NoName" : new_name; 
}

void CreatureCreator::configure_creature(Creature& c, const std::string& new_name, int new_health) {
    c.name = new_name;
    c.health = new_health;
    std::cout << "[Creator] Creature changed" << std::endl;
}

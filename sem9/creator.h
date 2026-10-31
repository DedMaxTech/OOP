#pragma once
#include <string>

class Creature;

void set_creature_name(Creature& creature, const std::string& new_name);

class CreatureCreator {
public:
    static void configure_creature(Creature& c, const std::string& new_name, int new_health);
};
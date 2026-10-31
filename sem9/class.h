#pragma once

#include <iostream>
#include <string>
#include "doctor.h"

class Doctor; 
class CreatureCreator;

class Creature {
private:
    const std::string id;
    std::string name;
    int health;
    int *arr;

    friend void set_creature_name(Creature& creature, const std::string& new_name);
    friend class CreatureCreator;
    friend void Doctor::heal(Creature& c, int amount);

public:
    Creature();
    Creature(const std::string& new_id, const std::string& new_name, int new_health);
    Creature(const Creature& other);
    ~Creature();

    Creature& operator=(const Creature& other);

    const std::string& get_id() const;
    const std::string& get_name() const;
    int get_health() const;
    
    void set_name(const std::string& new_name);
    void set_health(int new_health);
};
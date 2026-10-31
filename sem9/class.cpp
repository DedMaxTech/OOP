#include "class.h"
#include "doctor.h"

Creature::Creature() 
    : id("default_id"), name("Unknown"), health(100), arr(new int[10]{}) {
    std::cout << "Default" << std::endl;
}

Creature::Creature(const std::string& new_id, const std::string& new_name, int new_health) 
    : id(new_id.empty() ? "fallback_id" : new_id), 
      name(new_name.empty() ? "NoName" : new_name), 
      health(new_health), 
      arr(new int[10]{}) {
    std::cout << "Initialization" << std::endl;
}

Creature::Creature(const Creature& other) 
    : id(other.id + "_copy"),
      name(other.name), 
      health(other.health),
      arr(new int[10]{}) { 
    std::cout << "Copy" << std::endl;
}

Creature::~Creature() {
    delete[] arr;
    arr = nullptr;
    std::cout << "Deleted" << std::endl;
}

Creature& Creature::operator=(const Creature& other) {
    std::cout << "Copy operator" << std::endl;
    if (this != &other) {
        name = other.name;
        health = other.health;
    }
    return *this;
}

const std::string& Creature::get_id() const {
    return this->id;
}

const std::string& Creature::get_name() const {
    return this->name;
}

int Creature::get_health() const {
    return this->health;
}

void Creature::set_name(const std::string& new_name) {
    this->name = new_name.empty() ? "NoName" : new_name;
}

void Creature::set_health(int new_health) {
    this->health = new_health;
}
#include "class.h"
#include <algorithm>
#include <random>

Creature::Creature() : id("default_id"), name("Unknown"), health(100), arr(new int[10]{}) {
    std::cout << "[Creature] Default constructor\n";
}

Creature::Creature(const std::string& new_id, const std::string& new_name, int new_health)
    : id(new_id.empty() ? "fallback_id" : new_id),
      name(new_name.empty() ? "NoName" : new_name),
      health(new_health),
      arr(new int[10]{}) {
    std::cout << "[Creature] Initialization constructor for: " << name << "\n";
}

Creature::Creature(const Creature& other)
    : id(other.id + "_copy"), name(other.name), health(other.health), arr(new int[10]{}) {
    std::copy(other.arr, other.arr + 10, arr);
    std::cout << "[Creature] Copy constructor\n";
}

Creature::~Creature() {
    delete[] arr;
    arr = nullptr;
    std::cout << "[Creature] Deleted: " << name << "\n";
}

Creature& Creature::operator=(const Creature& other) {
    std::cout << "[Creature] Copy operator\n";
    if (this != &other) {
        name = other.name;
        health = other.health;
        std::copy(other.arr, other.arr + 10, arr);
    }
    return *this;
}

const std::string& Creature::get_id() const { return this->id; }
const std::string& Creature::get_name() const { return this->name; }
int Creature::get_health() const { return this->health; }

void Creature::set_name(const std::string& new_name) {
    this->name = new_name.empty() ? "NoName" : new_name;
}

void Creature::set_health(int new_health) {
    this->health = new_health;
}

Archer::Archer(const std::string& id, const std::string& name, int health, int arrows)
    : Creature(id, name, health), arrows_quantity(std::clamp(arrows, 0, max_arrows)) {}

void Archer::show_arrows_quantity() const {
    std::cout << "Arrows: " << arrows_quantity << '\n';
}

void Archer::shoot() const {
    if (arrows_quantity > 0) {
        std::cout << get_name() << " shoots an arrow!\n";
    } else {
        std::cout << get_name() << " has no arrows left!\n";
    }
}

FlyingCreature::FlyingCreature(const std::string& id, const std::string& name, int health, double altitude)
    : Creature(id, name, health), flight_altitude(altitude < 0.0 ? 0.0 : altitude) {}

double FlyingCreature::get_altitude() const {
    return flight_altitude;
}

void FlyingCreature::set_altitude(double altitude) {
    flight_altitude = (altitude < 0.0 ? 0.0 : altitude);
}

void FlyingCreature::fly() const {
    std::cout << get_name() << " is flying at altitude " << flight_altitude << " meters.\n";
}

FlyingArcher::FlyingArcher(const std::string& id, const std::string& name, int health, int arrows, double altitude)
    : Creature(id, name, health),
      Archer(id, name, health, arrows),
      FlyingCreature(id, name, health, altitude) {}

void FlyingArcher::show_status() const {
    std::cout << "--- Flying Archer Status ---\n"
              << "ID: " << get_id() << "\n"
              << "Name: " << get_name() << "\n"
              << "Health: " << get_health() << "\n"
              << "Altitude: " << get_altitude() << " m\n";
    show_arrows_quantity();
    std::cout << "----------------------------\n";
}

void Sniper::show_weapon() const {
    static std::mt19937 generator(std::random_device{}());
    std::bernoulli_distribution bow(0.5);
    std::cout << "Ready to use " << (bow(generator) ? "bow" : "rifle") << '\n';
}
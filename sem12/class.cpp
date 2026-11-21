#include "class.h"
#include <algorithm>

Creature::Creature() : id("default_id"), name("Unknown"), health(100), arr(new int[10]{}) {}

Creature::Creature(const std::string& new_id, const std::string& new_name, int new_health)
    : id(new_id.empty() ? "fallback_id" : new_id),
      name(new_name.empty() ? "NoName" : new_name),
      health(new_health),
      arr(new int[10]{}) {}

Creature::Creature(const Creature& other)
    : id(other.id + "_copy"), name(other.name), health(other.health), arr(new int[10]{}) {
    std::copy(other.arr, other.arr + 10, arr);
}

Creature::~Creature() {
    delete[] arr;
    arr = nullptr;
}

Creature& Creature::operator=(const Creature& other) {
    if (this != &other) {
        name = other.name;
        health = other.health;
        std::copy(other.arr, other.arr + 10, arr);
    }
    return *this;
}

const std::string& Creature::get_id() const { return id; }
const std::string& Creature::get_name() const { return name; }
int Creature::get_health() const { return health; }

void Creature::set_name(const std::string& new_name) {
    name = new_name.empty() ? "NoName" : new_name;
}

void Creature::set_health(int new_health) { health = new_health; }

void Creature::info() const {
    std::cout << "[Creature] Name: " << name << ", HP: " << health << '\n';
}



CommonCreature::CommonCreature(const std::string& id, const std::string& name, int health)
    : Creature(id, name, health) {}

void CommonCreature::fight() const {
    std::cout << "[CommonCreature] Name: " << get_name() << ", attacks\n";
}

void CommonCreature::info() const {
    std::cout << "[CommonCreature] Name: " << get_name() << ", HP: " << get_health() << '\n';
}




Archer::Archer(const std::string& id, const std::string& name, int health, int arrows)
    : CommonCreature(id, name, health), arrows_quantity(std::clamp(arrows, 0, max_arrows)) {}

void Archer::show_arrows_quantity() const {
    std::cout << "Arrows: " << arrows_quantity << '\n';
}

void Archer::shoot() const {
    if (arrows_quantity > 0) {
        std::cout << get_name() << " shoots an arrow\n";
    } else {
        std::cout << get_name() << " has no arrows left\n";
    }
}

void Archer::fight() const {
    std::cout << "[Archer] Name: " << get_name() << ", takes aim... ";
    shoot();
}

void Archer::info() const {
    std::cout << "[Archer] Name: " << get_name() << ", Arrows: " << arrows_quantity << '\n';
}




FlyingArcher::FlyingArcher(const std::string& id, const std::string& name, int health, int arrows, double altitude)
    : Archer(id, name, health, arrows), flight_altitude(altitude < 0.0 ? 0.0 : altitude) {}

double FlyingArcher::get_altitude() const { return flight_altitude; }

void FlyingArcher::set_altitude(double altitude) {
    flight_altitude = (altitude < 0.0 ? 0.0 : altitude);
}

void FlyingArcher::fly() const {
    std::cout << get_name() << " is flying at altitude " << flight_altitude << " meters.\n";
}

void FlyingArcher::show_status() const {
    std::cout << "--- Flying Archer Status ---\n"
              << "ID: " << get_id() << "\n"
              << "Name: " << get_name() << "\n"
              << "Health: " << get_health() << "\n"
              << "Altitude: " << get_altitude() << " m\n";
    show_arrows_quantity();
    std::cout << "----------------------------\n";
}

void FlyingArcher::fight() const {
    std::cout << "[FlyingArcher] Name: " << get_name() << ", attacks from the sky. ";
    shoot();
}

void FlyingArcher::info() const {
    std::cout << "[FlyingArcher] Name: " << get_name() << ", Altitude: " << flight_altitude << "m\n";
}

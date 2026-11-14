#pragma once
#include <iostream>
#include <string>

class Creature {
private:
    const std::string id;
    std::string name;
    int health;
    int* arr;

public:
    Creature();
    Creature(const std::string& new_id, const std::string& new_name, int new_health);
    Creature(const Creature& other);
    virtual ~Creature();

    Creature& operator=(const Creature& other);

    const std::string& get_id() const;
    const std::string& get_name() const;
    int get_health() const;

    void set_name(const std::string& new_name);
    void set_health(int new_health);
};

class Archer : virtual public Creature {
private:
    int arrows_quantity;

public:
    static constexpr int max_arrows = 30;
    Archer(const std::string& id, const std::string& name, int health, int arrows);
    void show_arrows_quantity() const;
    void shoot() const;
};

class FlyingCreature : virtual public Creature {
private:
    double flight_altitude;

public:
    FlyingCreature(const std::string& id, const std::string& name, int health, double altitude);
    double get_altitude() const;
    void set_altitude(double altitude);
    void fly() const;
};

class FlyingArcher : public Archer, public FlyingCreature {
public:
    FlyingArcher(const std::string& id, const std::string& name, int health, int arrows, double altitude);
    void show_status() const;
};

class Sniper final : private Archer {
public:
    using Archer::Archer;
    using Archer::show_arrows_quantity;
    void show_weapon() const;
};
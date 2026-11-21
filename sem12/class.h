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

    virtual void fight() const = 0;
    void info() const;
};

class CommonCreature : public Creature {
public:
    CommonCreature(const std::string& id, const std::string& name, int health);
    
    void fight() const override;
    void info() const;
};

class Archer : public CommonCreature {
private:
    int arrows_quantity;

public:
    static constexpr int max_arrows = 30;

    Archer(const std::string& id, const std::string& name, int health, int arrows);

    void show_arrows_quantity() const;
    void shoot() const;
    
    void fight() const override;
    void info() const;
};

class FlyingArcher : public Archer {
private:
    double flight_altitude;

public:
    FlyingArcher(const std::string& id, const std::string& name, int health, int arrows, double altitude);

    double get_altitude() const;
    void set_altitude(double altitude);
    void fly() const;
    void show_status() const;

    void fight() const override;
    void info() const;
};

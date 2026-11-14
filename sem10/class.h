#pragma once

#include <iostream>
#include <string>


class Creature {
private:
    const std::string id;
    std::string name;
    int health;
    int *arr;


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

class Archer : public Creature {
private:
    int arrows_quantity;

public:
    static constexpr int max_arrows = 30;

    Archer(const std::string& id, const std::string& name, int health, int arrows);
    void show_arrows_quantity() const;
};

class Sniper final : private Archer {
public:
    using Archer::Archer;
    using Archer::show_arrows_quantity;

    void show_weapon() const;
};

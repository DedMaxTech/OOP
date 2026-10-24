#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>

template <typename T = int>
class Creature {
    static_assert(std::is_arithmetic_v<T>, "Health type must be numeric");
private:
    inline static int count = 0;
    inline static int next_id = 0;

    const std::string id;
    std::string name;
    T health;
    const int unique_id = ++next_id;

    static T normalize_health(T value) {
        if (value < 0)
            throw std::invalid_argument("Health must be >= 0");
        return value;
    }

public:
    inline static const std::string class_name = "Creature";

    Creature() : id("default_id"), name("Unknown"), health(100) {
        count++;
        std::cout << "Default init, count=" << count << std::endl;
    }

    Creature(const std::string& new_id, const std::string& new_name, T new_health)
        : id(new_id.empty() ? "fallback_id" : new_id),
          name(new_name.empty() ? "NoName" : new_name),
          health(normalize_health(new_health)) {
        count++;
        std::cout << "Initialization, count=" << count << std::endl;
    }

    Creature(const Creature& other)
        : id(other.id + "_copy"),
          name(other.name),
          health(other.health) {
        count++;
        std::cout << "Copy init, count=" << count  << std::endl;
    }
    Creature(Creature&& other) noexcept 
        : id(std::move(other.id)),
          name(std::move(other.name)),
          health(std::move(other.health)) {
        count++;
        std::cout << "Move init, count=" << count  << std::endl;
    }
    ~Creature() {
        count--;
        std::cout << "Deleted, count=" << count << std::endl;
    }

    Creature& operator=(const Creature& other) {
        std::cout << "Copy operator=, count=" << count << std::endl;
        if (this != &other) {
            name = other.name;
            health = other.health;
        }
        return *this;
    }
    Creature& operator=(Creature&& other) noexcept  {
        std::cout << "Move operator=, count=" << count << std::endl;
        if (this != &other) {
            name = std::move(other.name);
            health = std::move(other.health);
        }
        return *this;
    }
    bool operator<(const Creature& other) const {
        return id<other.id;
    }
    std::string get_id() const {
        return this->id;
    }
    std::string get_name() const;
    T get_health() const;
    void set_name(const std::string& new_name) {
        this->name = new_name.empty() ? "NoName" : new_name;
    }
    void set_health(T new_health);
    void print_creature() const {
        std::cout << "id=" << id << ", name=" << name << ", health=" << health << std::endl;
    }
    static void print_count() {
        std::cout << "Count=" << count << std::endl;
    }
    friend std::ostream& operator << (std::ostream& out, const Creature& obj) {
        out << class_name << ", count=" << count << ", uid=" << obj.unique_id
            << ", id=" << obj.id << ", name=" << obj.name << ", health=" << obj.health;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Creature& obj) {
        std::string name;
        T health;
        if (in >> name >> health) {
            obj.set_health(health);
            obj.set_name(name);
        }
        return in;
    }

};

template <typename T>
T Creature<T>::get_health() const {
    return health;
}

template <typename T>
void Creature<T>::set_health(T new_health) {
    health = normalize_health(new_health);
}

template <typename T>
std::string Creature<T>::get_name() const {
    return name;
}

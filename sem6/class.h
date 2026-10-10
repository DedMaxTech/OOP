#include <iostream>
#include <string>

class Creature {
private:
    const std::string id;
    std::string name;
    int health;
    int *arr;

public:
    Creature() : id("default_id"), name("Unknown"), health(100), arr(new int[10]{}) {
        std::cout << "Default" << std::endl;
    }

    Creature(const std::string& new_id, const std::string& new_name, int new_health) 
        : id(new_id.empty() ? "fallback_id" : new_id), 
          name(new_name.empty() ? "NoName" : new_name), 
          health(new_health), 
          arr(new int[10]{}) {
        std::cout << "Initialization" << std::endl;
    }

    Creature(const Creature& other) 
        : id(other.id + "_copy"),
          name(other.name), 
          health(other.health) {
        std::cout << "Copy" << std::endl;
    }
    ~Creature() {
        delete[] arr;
    }

    Creature& operator=(const Creature& other) {
        std::cout << "Copy operator" << std::endl;
        if (this != &other) {
            name = other.name;
            health = other.health;
        }
        return *this;
    }
    const std::string& get_id() {
        return this->id;
    }
    const std::string& get_name() {
        return this->name;
    }
    const int get_health() {
        return this->health;
    }
    void set_name(const std::string& new_name) {
        this->name = new_name.empty() ? "NoName" : new_name;
    }
    void set_health(int new_health) {
        this->health = new_health;
    }
};
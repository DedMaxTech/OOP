#include <iostream>
#include <string>

class Creature {
private:
    inline static int count = 0;

    const std::string id;
    std::string name;
    int health;
    int *arr;

public:
    inline static const std::string class_name = "Creature";

    Creature() : id("default_id"), name("Unknown"), health(100), arr(new int[10]{}) {
        count++;
        std::cout << "Default init, count=" << count << std::endl;
    }

    Creature(const std::string& new_id, const std::string& new_name, int new_health) 
        : id(new_id.empty() ? "fallback_id" : new_id), 
          name(new_name.empty() ? "NoName" : new_name), 
          health(new_health), 
          arr(new int[10]{}) {
        count++;
        std::cout << "Initialization, count=" << count << std::endl;
    }

    Creature(const Creature& other) 
        : id(other.id + "_copy"),
          name(other.name), 
          health(other.health), 
          arr(new int[10]{}) {
        count++;
        std::cout << "Copy init, count=" << count  << std::endl;
    }
    ~Creature() {
        if (arr != nullptr) delete[] arr;
            arr = nullptr;

        count--;
        std::cout << "Deleted, count=" << count << std::endl;
    }

    Creature& operator=(const Creature& other) {
        std::cout << "Copy operator" << std::endl;
        if (this != &other) {
            name = other.name;
            health = other.health;
        }
        return *this;
    }
    bool operator<(const Creature& other) const {
        return id<other.id;
    }
    std::string get_id() const {
        return this->id;
    }
    std::string get_name() const {
        return this->name;
    }
    int get_health() const {
        return this->health;
    }
    void set_name(const std::string& new_name) {
        this->name = new_name.empty() ? "NoName" : new_name;
    }
    void set_health(int new_health) {
        this->health = new_health;
    }
    void print_creature() {
        std::cout << "id=" << id << ", name=" << name << ", health=" << health << std::endl;
    }
    static void print_count() {
        std::cout << "Count=" << count << std::endl;
    }
    friend std::ostream& operator << (std::ostream& out, const Creature& obj) {
        out << "id=" << obj.id << ", name=" << obj.name << ", health=" << obj.health << std::endl; 
        return out;
    }

};
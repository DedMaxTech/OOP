#include "class.h"

int main() {
    Creature default_creature;
    Creature hero("hero_001", "Aragorn", 150);
    std::cout << hero.get_id() << '\n';
    Creature broken_creature("", "", 50);
    Creature hero_clone = hero;
    std::cout << hero_clone.get_id() << '\n';
    default_creature = hero;
    std::cout << default_creature.get_id() << '\n';
    return 0;
}

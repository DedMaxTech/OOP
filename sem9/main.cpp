#include "class.h"
#include "creator.h"
#include "doctor.h"
#include "army.h"

int main() {
    Creature default_creature;
    Creature hero("hero_001", "Aragorn", 150);
    std::cout << hero.get_name() << ' ' << hero.get_health() << std::endl;

    CreatureCreator creator;
    creator.configure_creature(hero, "Smegl", 23);
    std::cout << hero.get_name() << ' ' << hero.get_health() << std::endl;

    Doctor doctor;
    doctor.heal(hero, 50);
    std::cout << hero.get_name() << ' ' << hero.get_health() << std::endl;

    Army army1(hero);
    Army army2(hero);
    Army army3(hero);

    return 0;
}

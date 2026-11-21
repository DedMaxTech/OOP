#include "class.h"

int main() {
    const int SIZE = 3;
    Creature* squad[SIZE] = {
        new CommonCreature("id_1", "Goblin", 50),
        new Archer("id_2", "Legolas", 100, 25),
        new FlyingArcher("id_3", "Griffon Rider", 150, 15, 120.5)
    };

    std::cout << "virtial flight\n";
    for (int i = 0; i < SIZE; ++i) {
        squad[i]->fight();
    }

    std::cout << "\ninfo\n";
    for (int i = 0; i < SIZE; ++i) {
        squad[i]->info();
    }

    for (int i = 0; i < SIZE; ++i) {
        delete squad[i];
    }

    return 0;
}

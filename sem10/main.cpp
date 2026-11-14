#include "class.h"

int main() {
    Creature hero("hero", "Aragorn", 150);
    std::cout << hero.get_name() << ' ' << hero.get_health() << '\n';

    std::cout << "--- Archer ---\n";
    Archer archer("archer", "Legolas", 100, 40);
    archer.show_arrows_quantity();
    std::cout << archer.get_name() << '\n';

    std::cout << "--- Sniper ---\n";
    Sniper sniper("sniper", "Robin", 100, 20);
    sniper.show_arrows_quantity();
    for (int i = 0; i < 5; ++i)
        sniper.show_weapon();
}

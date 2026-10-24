// #include "class.h"
// #include <limits>

// int main(){
//     std::cout << "static values: " << std::endl;
//     Creature<>::print_count();
//     std::cout << Creature<>::class_name << std::endl << std::endl;


//     std::cout << "Creature creation: " << std::endl;
//     Creature<> my_first_book ("Volkov Alexander", "The Wizard of Oz", 500);
//     my_first_book.print_creature();
//     my_first_book.print_count();
//     std::cout << my_first_book << std::endl;

//     std::cout << "Second Creature: " << std::endl;
//     Creature<> my_second_book {my_first_book};
//     std::cout << my_second_book << std::endl;
//     my_second_book.set_health(222);
//     my_first_book.set_health(111);
//     my_second_book.print_creature();


//     {
//         std::cout << " inside {} " << std::endl;
//         Creature<> my_second_book {my_first_book};
//         std::cout << my_second_book << std::endl;
//         my_second_book.set_health(30);
//         my_first_book.set_health(40);
//         my_second_book.print_creature();
//     }


//     std::cout << " outside {} " << std::endl;
//     my_second_book.print_creature();
//     std::cout << "Count of objects = "; Creature<>::print_count();


//     Creature<double> mage("mage", "Mage", 75.5);
//     std::cout << mage << '\n';

//     while (true) {
//         std::cout << "Enter name and health (>= 0): ";
//         try {
//             if (std::cin >> my_first_book) break;
//             std::cin.clear();
//             std::cout << "Health must be a number\n";
//         } catch (const std::invalid_argument& e) {
//             std::cout << e.what() << '\n';
//         }
//     }
//     std::cout << my_first_book << '\n';

//     return 0;
// }


#include "class.h"
#include <vector>
#include <list>
#include <set>

int main(){

    Creature c1 ("Volkov Alexander", "The Wizard of Oz", 500);
    c1.print_creature();
    Creature c2 = std::move(c1);
    c2.print_creature();
    c1.print_creature();
    return 0;
}

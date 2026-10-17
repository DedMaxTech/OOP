// #include "class.h"

// int main(){
//     std::cout << "static values: " << std::endl;
//     Creature::print_count(); 
//     std::cout << Creature::class_name << std::endl << std::endl;


//     std::cout << "Creature creation: " << std::endl;
//     Creature my_first_book ("Volkov Alexander", "The Wizard of Oz", 500);
//     my_first_book.print_creature();
//     my_first_book.print_count();     
//     std::cout << my_first_book << std::endl;
   
//     std::cout << "Second Creature: " << std::endl;
//     Creature my_second_book {my_first_book};
//     std::cout << my_second_book << std::endl;
//     my_second_book.set_health(222);
//     my_first_book.set_health(111);
//     my_second_book.print_creature();


//     {
//         std::cout << " inside {} " << std::endl;
//         Creature my_second_book {my_first_book};
//         std::cout << my_second_book << std::endl;
//         my_second_book.set_health(30);
//         my_first_book.set_health(40);
//         my_second_book.print_creature();
//     }


//     std::cout << " outside {} " << std::endl;
//     my_second_book.print_creature();
//     std::cout << "Count of objects = "; Creature::print_count();


//     return 0;
// }

#include "class.h"
#include <vector>
#include <list>
#include <set>

int main(){
    std::vector<Creature> vec {Creature("1", "Name 1", 100),
                                Creature("2", "Name 2", 200),
                                Creature("3", "Name 3", 300),
                                Creature("4", "Name 4", 400),
                                Creature("5", "Name 5", 500),
                                };
    std::cout << "AFTER VECTOR COUNT, ";Creature::print_count(); std::cout << std::endl;
    std::set<Creature> set {Creature("6", "Name 6", 100),
                                Creature("7", "Name 7", 200),
                                Creature("8", "Name 8", 300),
                                Creature("9", "Name 9", 400),
                                Creature("10", "Name 10", 500),
                                };
    std::cout << "AFTER SET COUNT, ";Creature::print_count(); std::cout << std::endl;
    std::list<Creature> list {Creature("11", "Name 11", 100),
                                Creature("12", "Name 12", 200),
                                Creature("13", "Name 13", 300),
                                Creature("14", "Name 14", 400),
                                Creature("15", "Name 15", 500),
                                };
    std::cout << "AFTER LIST COUNT, ";Creature::print_count(); std::cout << std::endl;
    return 0;
}

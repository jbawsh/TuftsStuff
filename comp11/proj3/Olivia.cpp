#include <iostream>
#include <string>



int main() {

        std::string name;

        std::cout << "Enter your name: " << std::endl;
        std::cin >> name;
        if (name == "Olivia" || name == "olivia" || name == "OLIVIA") {
                std::cout << "I love you!" << std::endl;
        } else {
                std::cout << "Wrong name silly..." << std::endl;
        }

        std::cout << name[0] << std::endl;

        return 0;
}

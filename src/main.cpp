#include <iostream>
#include <string>
#include "EmbeddedSystem.hpp"

int main()
{
    EmbeddedSystem system;
    std::string command;

    std::cout << "========================================\n";
    std::cout << "        EMBEDDED SYSTEM CLI v1.0        \n";
    std::cout << "========================================\n";
    while(true)
    {
        std::cout << "embedded> ";
        std::getline(std::cin, command);

        std::cout << "You entered: " << command << '\n';

        if(command == "exit" || command == "Exit" || command == "EXIT")
        {
            std::cout << "\nExiting EMBEDDED SYSYTEM CLI...\n";
            break;
        }
    }

    return 0;
}
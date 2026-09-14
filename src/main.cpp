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

        if(command == "exit" || command == "Exit" || command == "EXIT")
        {
            std::cout << "\nExiting Embedded System CLI...\n";
            break;
        }
        else if(command == "help" || command == "Help" || command == "HELP")
        {
            std::cout << "\nAvailable commands:\n";
            std::cout << "  help    Display this help message\n";
            std::cout << "  exit    Exit Embedded System CLI\n\n";
        }
        else
        {
            std::cout << "ERROR: Unknown command\n";
        }
    }

    return 0;
}
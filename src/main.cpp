#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
        std::stringstream stream(command);
        std::string token;
        std::vector<std::string> tokens;

        while(stream >> token)
        {
            tokens.push_back(token);
        }

        if(tokens.empty())
        {
            continue;
        }

        if(tokens[0] == "exit" || tokens[0] == "Exit" || tokens[0] == "EXIT")
        {
            std::cout << "\nExiting Embedded System CLI...\n";
            break;
        }
        else if(tokens[0] == "help" || tokens[0] == "Help" || tokens[0] == "HELP")
        {
            std::cout << "\nAvailable commands:\n";
            std::cout << "  help    Display this help message\n";
            std::cout << "  exit    Exit Embedded System CLI\n\n";
        }
        else if(tokens[0] == "gpio" || tokens[0] == "GPIO")
        {
            if(tokens.size() == 1)
            {
                std::cout << "ERROR: Missing GPIO subcommand\n";
            }
            else if(tokens[1] == "help" || tokens[1] == "Help" || tokens[1] == "HELP")
            {
                std::cout << "\nGPIO commands:\n";
                std::cout << "  mode    Set GPIO pin mode\n";
                std::cout << "  write   Write GPIO pin state\n";
                std::cout << "  read    Read GPIO pin state\n";
                std::cout << "  help    Display this help message\n\n";
            }
            else
            {
                std::cout << "ERROR: Unknown GPIO subcommand\n";
            }
        }
        else
        {
            std::cout << "ERROR: Unknown command\n";
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include "UART.hpp"

UART::UART()
{
    baudRate = 0;
    state = UNINITIALIZED;
}

void UART::begin(int baudRate)
{
    if(baudRate <= 0 || baudRate > 115200)
    {
        std::cout << "ERROR: Invalid baud rate\n";
        return;
    }

    this->baudRate = baudRate;
    state = READY;
}

void UART::send(std::string message)
{
    if(state == UNINITIALIZED)
    {
        std::cout << "ERROR: UART is not initialized\n";
        return;
    }
    
    std::cout << "UART TX: " << message << '\n';
}

UARTState UART::status()
{
    return state;
}
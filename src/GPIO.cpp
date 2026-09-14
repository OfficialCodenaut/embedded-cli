#include <iostream>
#include "GPIO.hpp"

GPIO::GPIO()
{
    for (int i = 0; i < 30; i++)
    {
        pins[i].mode = INPUT;
        pins[i].state = LOW;
    }
}

void GPIO::setMode(int pin, PinMode mode)
{
    if (pin < 0 || pin >= 30){
        std::cout << "ERROR: Invalid GPIO pin\n";
        return;
    }

    pins[pin].mode = mode;

    switch (mode)
    {
        case INPUT:
        {
            std::cout << "GPIO" << pin << " = INPUT\n";
            break;
        }

        case OUTPUT:
        {
            std::cout << "GPIO" << pin << " = OUTPUT\n";
            break;
        }
    }
}

void GPIO::write(int pin, PinState state)
{
    if (pin < 0 || pin >= 30)
    {
        std::cout << "ERROR: Invalid GPIO pin\n";
        return;
    }

    if (pins[pin].mode == INPUT)
    {
        std::cout << "ERROR: GPIO pin is configured as INPUT\n";
        return;   
    }

    pins[pin].state = state;

    switch (state)
    {
        case HIGH:
        {
            std::cout << "GPIO" << pin << " = HIGH\n";
            break;
        }

        case LOW:
        {
            std::cout << "GPIO" << pin << " = LOW\n";
            break;
        }
    }
}

PinState GPIO::read(int pin)
{
    if (pin < 0 || pin >= 30){
        std::cout << "ERROR: Invalid GPIO pin\n";
        return LOW;
    }

    switch (pins[pin].state)
    {
        case HIGH:
        {
            std::cout << "GPIO" << pin << " = HIGH\n";
            break;
        }

        case LOW:
        {
            std::cout << "GPIO" << pin << " = LOW\n";
            break;
        }
    }

    return pins[pin].state;
}
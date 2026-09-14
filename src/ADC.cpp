#include <iostream>
#include "ADC.hpp"

ADC::ADC()
{
    for(int i = 0; i < 8; i++)
    {
        channels[i].value = 0;
    }
}

void ADC::setValue(int channel, int value)
{
    if(channel < 0 || channel > 7)
    {
        std::cout << "ERROR: Invalid ADC channel\n";
        return;
    }

    if(value < 0 || value > 1023)
    {
        std::cout << "ERROR: ADC value must be between 0 and 1023\n";
        return;
    }

    channels[channel].value = value;
}

int ADC::read(int channel)
{
    if(channel < 0 || channel > 7)
    {
        std::cout << "ERROR: Invalid ADC channel\n";
        return 0;
    }

    std::cout << "ADC" << channel << " = " << channels[channel].value << '\n'; 

    return channels[channel].value;
}
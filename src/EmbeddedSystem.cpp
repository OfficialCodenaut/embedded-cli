#include "EmbeddedSystem.hpp"

EmbeddedSystem::EmbeddedSystem()
{

}

GPIO& EmbeddedSystem::getGPIO()
{
    return gpio;
}

ADC& EmbeddedSystem::getADC()
{
    return adc;
}

UART& EmbeddedSystem::getUART()
{
    return uart;
}
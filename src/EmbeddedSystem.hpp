#ifndef EMB_HPP
#define EMB_HPP

#include "GPIO.hpp"
#include "ADC.hpp"
#include "UART.hpp"

class EmbeddedSystem
{
    private:
    GPIO gpio;
    ADC adc;
    UART uart;

    public:
    EmbeddedSystem();
    GPIO& getGPIO();
    ADC& getADC();
    UART& getUART();
};

#endif
#ifndef UART_HPP
#define UART_HPP

#include <string>

enum UARTState
{
    UNINITIALIZED,
    READY
};

class UART
{
    private:
    int baudRate;
    UARTState state;

    public:
    UART();

    void begin(int baudRate);
    void send(std::string message);
    UARTState status();
};

#endif
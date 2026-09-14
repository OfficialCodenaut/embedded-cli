#ifndef GPIO_HPP
#define GPIO_HPP

enum PinMode
{
    INPUT,
    OUTPUT
};

enum PinState
{
    LOW,
    HIGH
};

struct Pin
{
    PinMode mode;
    PinState state;
};

class GPIO
{
    private:
    Pin pins[30];

    public:
    GPIO();

    void setMode(int pin, PinMode mode);
    void write(int pin, PinState state);
    PinState read(int pin);
};

#endif
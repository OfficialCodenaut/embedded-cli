#ifndef ADC_HPP
#define ADC_HPP

struct ADCChannel
{
    int value;
};

class ADC
{
    private:
    ADCChannel channels[8];

    public:
    ADC();

    void setValue(int channel, int value);
    int read(int channel);
};

#endif
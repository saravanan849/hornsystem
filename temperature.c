#include "temperature.h"
extern unsigned int default_dutycycle;
void temperature()
{

    uint16_t ADC_value;
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    ADC_value = ADC;

    if(ADC_value > 1000)
    {

        OCR0A = 0;
    }
    if(ADC_value > 500 && ADC_value < 1000)
    {

        OCR0A = 26;
    }
    if(ADC_value <= 500)
    {

        OCR0A = default_dutycycle;
    }
}

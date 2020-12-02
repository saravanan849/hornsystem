#include "gpio.h"
uint16_t ADC_value;

void temperature(const int flag)
{
while (1)
    {
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    ADC_value = ADC;

    if(flag==1)

        {if(ADC_value>500 && ADC_value<1000)
        {
            OCR0A=26;
        }
        else if (ADC_value>1000)
        {
            OCR0A=255;
        }
        else if (ADC_value <=500)
        {
            OCR0A=value; //previous duty cycle is maintained
        }
        }


    }
}

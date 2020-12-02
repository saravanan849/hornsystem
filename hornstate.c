#include "GPIO.h"

void horn()
{
    int value;
     uint8_t PIN_READ=0x00;
    PIN_READ=PIND;
    if (PIN_READ |= (1<<PD3)) //ENGINE ON
        {
        if (PIN_READ |= (1<<PD7)) //HORN ON
            {
                value=77;
                OCR0A=value;
                while(1)
                {

                }
              flag.bit=1;
                void (*itemperature)(const int)=0;
                itemperature=temperature;
                (*itemperature)(flag.bit);
            }
            else if (PIN_READ &= ~(1<<PD7)) //HORN OFF
            {

                value=255;
                OCR0A=value;

                while(1)
                {

                }


            }

}
else if (PIN_READ &= ~(1<<PD3))
    {
    calibration();
}
}

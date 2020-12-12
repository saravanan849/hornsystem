#include "Hornstate.h"
extern unsigned int default_dutycycle;
void horn()
{
    uint16_t PIN_READ = PIND; //
    if(!((PIN_READ) & (1<<PD1)))  //ENGINE ON
    {
        if(!((PIN_READ) & (1<<PD7)))  //HORN ON
        {
            OCR0A = default_dutycycle;
            temperature();
        }
        else if((PIN_READ) & (1<<PD7))
        {
            OCR0A = 0;
        }
    }
    else if((PIN_READ) & (1<<PD1))
    {
        OCR0A = 0;
    }
}

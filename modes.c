#include "modes.h"
extern void horn();
void modes()
{
    uint16_t PIN_READ = PIND;
    if(!((PIN_READ) & (1<<PD1)))  //ENGINE ON
    {
        horn();
    }
    else if((PIN_READ) & (1<<PD1))
    {
        SET_BIT(PORTD,PD4);
    }
}

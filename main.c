/*
 */

#include "GPIO.h"

int main(void)
{
    configuration();

    while(1)
    {
       horn();
    }

    return 0;
}
ISR(INT0_vect)
{
    cli();
    Flag_bit.Flag_ISR0=1;
    sei();
}
ISR(INT1_vect)
{
    cli();
    Flag_bit.Flag_ISR1=1;
    sei();
}


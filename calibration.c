#include "GPIO.h"
extern int value;
void calibration()
{
    if(Flag_bit.Flag_ISR1==1 && Flag_bit.Flag_ISR0==0)
    {
        value+=12.5;
        OCR0A=value;
        Flag_bit.Flag_ISR1=0;
    }
    if(Flag_bit.Flag_ISR1==0 && Flag_bit.Flag_ISR0==1)
    {
        value-=12.5;
        OCR0A=value;
        Flag_bit.Flag_ISR0=0;
    }

}


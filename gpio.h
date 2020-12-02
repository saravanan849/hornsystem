#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <avr/interrupt.h>

#define SET_BIT(PORT,BIT) PORT |= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT &= ~(1<<BIT)

int value;
struct {
     volatile unsigned int bit : 1 ;
}
flag;
struct{
    volatile unsigned int Flag_ISR1: 1;
    volatile unsigned int Flag_ISR0: 1;
    }Flag_bit;
extern void horn();
extern void temperature(const int);
extern void calibration();
#endif // GPIO_H


#ifndef GPIO_H
#define GPIO_H

#include<stdint.h>
#include<avr/io.h>
#include<avr/interrupt.h>

#define SET_BIT(PORT,BIT) PORT |= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT &= ~(1<<BIT)

extern void configuration();
extern void horn();
unsigned int default_dutycycle = 77;

#endif

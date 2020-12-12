#include "GPIO.h"
void configuration()
{
    CLR_BIT(DDRD,PD1);  //ENGINE
    SET_BIT(PORTD,PD1);
    CLR_BIT(DDRD,PD7);  //HORN
    SET_BIT(PORTD,PD7);

    
    SET_BIT(PORTD,PD6);

    SET_BIT(DDRD,PD4);

    TCCR0A |= ((1<<WGM00) | (1<<WGM01));    //setting it to fast PWM mode
    TCCR0A |= (1<<COM0A1);
    TCCR0A &= ~(1<<COM0A0);
    TCNT0 = 0x00;

    TCCR0B |= ((1<<CS00) | (1<<CS02)); //Prescaler setting 1024
    TCCR0B &= ~(1<<CS01);

    ADMUX &= 0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADEN);
    sei();

}

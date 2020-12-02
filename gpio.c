#include "GPIO.h"


void configuration()
{
     CLR_BIT(DDRD,PD1);  //PD1 is INPUT - SW1
    SET_BIT(PORTD,PD1); //PULL-UP CONFIGURATION

    CLR_BIT(DDRD,PD7);  //PD7 is INPUT - SW2
    SET_BIT(PORTD,PD7); //PULL-UP CONFIGURATION

    SET_BIT(DDRD,PD6);  //for PWM output
    CLR_BIT(PORTD,PD6);

    CLR_BIT(DDRD,PD3);  //PD3 is EXTERNAL INTERRUPT - GPIO+
    SET_BIT(PORTD,PD3);

    CLR_BIT(DDRD,PD2);  //PD2 is EXTERNAL INTERRUPT - GPIO-
    SET_BIT(PORTD,PD2);

    EICRA |= (1 << ISC11);
    EICRA &= ~(1 << ISC10);
    EICRA |= (1 << ISC01);
    EICRA &= ~(1 << ISC00);
    EIMSK |= (1 << INT1);
    EIMSK |= (1 << INT0);

    TCCR0A |= ((1<<WGM00) | (1<<WGM01));    //setting it to fast PWM mode
    TCCR0A |= (1<<COM0A1);
    TCCR0A &= ~(1<<COM0A0);
    TCNT0 = 0x00;

    OCR0A=77;
    TCCR0B |= ((1<<CS00) | (1<<CS02)); //Prescaler setting 1024
    TCCR0B &= ~(1<<CS01);


    ADMUX &= 0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADEN);
    sei();
}



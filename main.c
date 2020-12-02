#include <avr/io.h>
#include <avr/interrupt.h>

#define SET_BIT(PORT,BIT) PORT |= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT &= ~(1<<BIT)
struct {
     volatile unsigned int bit : 1 ;
}flag;

struct{
    volatile unsigned int Flag_ISR1: 1; //INTERRUPT 1 - PD3 PIN
    volatile unsigned int Flag_ISR0: 1; //INTERRUPT 0 - PD2 PIN
    }Flag_bit;

int value;
void temperature(const int);    //function declaration

int main(void)
{

     CLR_BIT(DDRD,PD1);  //PD1 is INPUT - SW1
    SET_BIT(PORTD,PD1); //PULL-UP CONFIGURATION

    CLR_BIT(DDRD,PD7);  //PD7 is INPUT - SW2
    SET_BIT(PORTD,PD7); //PULL-UP CONFIGURATION

    SET_BIT(DDRD,PD6);  //for PWM output

    CLR_BIT(DDRD,PD3);  //PD3 is EXTERNAL INTERRUPT - GPIO+
    SET_BIT(PORTD,PD3);

    CLR_BIT(DDRD,PD2);  //PD2 is EXTERNAL INTERRUPT - GPIO-
    SET_BIT(PORTD,PD2);

    EICRA |= (1 << ISC11);
    EICRA |= (1 << ISC10); //setting to rising edge
    EICRA |= (1 << ISC01);
    EICRA |= (1 << ISC00);
    EIMSK |= (1 << INT1);
    EIMSK |= (1 << INT0);
    sei();


    while(1)
    {
    uint8_t PIN_READ=0x00;
    PIN_READ=PIND;
    if (PIN_READ |= (1<<PD3)) //ENGINE ON
        {
        if (PIN_READ |= (1<<PD7)) //HORN ON
            {
                TCCR0A |= ((1<<WGM00) | (1<<WGM01));    //setting it to fast PWM mode
                TCCR0B &= ~(1<<WGM02);
                TCCR0A |= (1<<COM0A1);
                TCCR0A &= ~(1<<COM0A0);
                TCNT0 = 0x00;
                value = 77; //To generate 30% duty cycle
                OCR0A=value;
                TCCR0B |= ((1<<CS00) | (1<<CS02)); //Prescaler setting 1024
                TCCR0B &= ~(1<<CS01);
                sei();
                while(1)
                {

                }
                flag.bit=1;
                void (*itemperature)(const int)=0; //function pointer
                itemperature=temperature;
                (*itemperature)(flag.bit);
            }
            else if (PIN_READ &= ~(1<<PD7)) //HORN OFF
            {
                TCCR0A |= ((1<<WGM00) | (1<<WGM01));    //setting it to fast PWM mode
                TCCR0A |= (1<<COM0A1);
                TCCR0A &= ~(1<<COM0A0);
                TCNT0 = 0x00;
                value=255;
                OCR0A=value;
                TCCR0B |= ((1<<CS00) | (1<<CS02));
                TCCR0B &= ~(1<<CS01);
                sei();
                while(1)
                {

                }


            }

}
else if (PIN_READ &= ~(1<<PD3)) //ENGINE IS OFF
    {
    if(Flag_bit.Flag_ISR1==1 && Flag_bit.Flag_ISR0==0)  //GPIO +
    {
        value+=12.5;    //increasing duty cycle 5% for every push
        OCR0A=value;
        Flag_bit.Flag_ISR1=0;
    }
    if(Flag_bit.Flag_ISR1==0 && Flag_bit.Flag_ISR0==1)  //GPIO -
    {
        value-=12.5;    //decreasing duty cycle 5% for every push
        OCR0A=value;
        Flag_bit.Flag_ISR0=0;
    }
}
    }

    return 0;
}

void temperature(const int flag1)
{
    uint16_t ADC_value;
    ADMUX &= 0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADEN);
    while (1)
    {
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    ADC_value = ADC;

    if(flag1==1)
    {
        if(ADC_value>500 && ADC_value<1000)
        {
            OCR0A=26;
        }
        else if (ADC_value>1000)
        {
            OCR0A=255;
        }
        else if (ADC_value <=500)
        {
            OCR0A=value;
        }

    }
    }
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

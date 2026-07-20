#include <stdint.h>
#include "ATMEGA32REGMAP.h>
#include "BITMATH.h"
#include <util/delay.h>

#define G1 0
#define G2 1
#define G3 2
#define G4 3

#define LED_ON 1
#define LED_OFF 0


#define DDRA_REG *((volatile uint8_t*)0x3A)
#define DDRB_REG *((volatile uint8_t*)0x37)
#define DDRC_REG *((volatile uint8_t*)0x34)
#define DDRD_REG *((volatile uint8_t*)0x31)

#define PORTA_REG *((volatile uint8_t*)0x3B)
#define PORTB_REG *((volatile uint8_t*)0x38)
#define PORTC_REG *((volatile uint8_t*)0x35)
#define PORTD_REG *((volatile uint8_t*)0x32)

void LED_Init(uint8_t GroupName, uint8_t PinNumber)
{
    switch(GroupName)
    {
        case G1: DDRA_REG |= (1 << PinNumber);
        
        break;
        
        case G2: DDRB_REG |= (1 << PinNumber);
        
        break;
        
        case G3: DDRC_REG |= (1 << PinNumber);
        
        break;
        
        case G4: DDRD_REG |= (1 << PinNumber);
        
        break;
    }

}

void LED_Write(uint8_t GroupName, uint8_t PinNumber, uint8_t State)
{
    if(State == LED_ON)
    {
        switch(GroupName)
    {
        case G1: PORTA_REG |= (1 << PinNumber);
        
        break;
        
        case G2: PORTB_REG |= (1 << PinNumber);
        
        break;
        
        case G3: PORTC_REG |= (1 << PinNumber);
        
        break;
        
        case G4: PORTD_REG |= (1 << PinNumber);
        
        break;
    }

    }
    else if(State == LED_OFF)
    {
        switch(GroupName)
    {
        case G1: PORTA_REG &= ~(1 << PinNumber);
        
        break;
        
        case G2: PORTB_REG &= ~(1 << PinNumber);
        
        break;
        
        case G3: PORTC_REG &= ~(1 << PinNumber);
        
        break;
        
        case G4: PORTD_REG &= ~(1 << PinNumber);
        
        break;
    }

    }
}

void LED_Toggle(uint8_t GroupName, uint8_t PinNumber)
{

    switch(GroupName){
     
        case G1: PORTA_REG ^= (1 << PinNumber);
        
        break;
        
        case G2: PORTB_REG ^= (1 << PinNumber);
        
        break;
        
        case G3: PORTC_REG ^= (1 << PinNumber);
        
        break;
        
        case G4: PORTD_REG ^= (1 << PinNumber);
        
        break;


    }

}

int main()
{
    uint8_t PinNumber;
    LED_Init(G2, PinNumber);

    while(1)
    {
        LED_Toggle(G2, PinNumber);
        _delay_ms(1000);
    }

    return 0;
}

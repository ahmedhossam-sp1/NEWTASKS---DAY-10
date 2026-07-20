#include <stdint.h>
#include "ATMEGA32REGMAP.h"
#include "BITMATH.h"
#include <util/delay.h>

#define G1 0
#define G2 1
#define G3 2
#define G4 3


static const uint8_t Segment_Numbers[10] = {
    0x3F, // 0 -> 0b00111111
    0x06, // 1 -> 0b00000110
    0x5B, // 2 -> 0b01011011
    0x4F, // 3 -> 0b01001111
    0x66, // 4 -> 0b01100110
    0x6D, // 5 -> 0b01101101
    0x7D, // 6 -> 0b01111101
    0x07, // 7 -> 0b00000111
    0x7F, // 8 -> 0b01111111
    0x6F  // 9 -> 0b01101111
};


void Segment_Init(uint8_t GroupName)
{
    switch(GroupName)
    {
        case G1: 
         DDRA_REG = 0xFF;
         break;

         case G2: 
         DDRB_REG = 0xFF;
         break;

         case G3: 
         DDRC_REG = 0xFF;
         break;

         case G4: 
         DDRD_REG = 0xFF;
         break;

    }
}

void DisplayNumber(uint8_t GroupName, uint8_t Number)
{
    if(Number <= 9)
    {
        switch(GroupName)
        {
             case G1: 
          PORTA_REG = Segment_Numbers[Number];
          break;

          case G2: 
         PORTB_REG = Segment_Numbers[Number];
         break;

          case G3: 
          PORTC_REG = Segment_Numbers[Number];
          break;

          case G4: 
          PORTD_REG = Segment_Numbers[Number];
          break;

        }
    }

    else if(Number <= 99 )
    {
        uint8_t ones = Number % 10;
        uint8_t Tens = Number / 10;
    }
}

void DisplayRang(uint8_t GroupName,uint8_t Start , uint8_t End )
{
    uint8_t i = 0;
    for(i = Start; i<= End; i++)
    {
        DisplayNumber(GroupName, i);
        _delay_ms(1000);
    }
}

int main()
{
    Segment_Init(G1);
    
    while(1)
    {
        DisplayRang(G1, 0, 9);
    }
    
    
    return 0;
}

/*
 * File:   main.c
 * Author: derslik3-07
 *
 * Created on September 2, 2025, 11:14 AM
 */


#include <xc.h>
#include <stdint.h>

#define BUTTONPIN 0
#define LEDPIN 2

volatile uint8_t *PORTBPtr = (volatile uint8_t*)0x6;
volatile uint8_t *TRISBPtr = (volatile uint8_t*)0x86;
volatile uint8_t *OPTIONPtr= (volatile uint8_t*)0x81;
volatile uint8_t *INTCONPtr = (volatile uint8_t*)0x0B;

int main(){
*PORTBPtr &= ~(1 << LEDPIN);
*PORTBPtr &= ~(1 << BUTTONPIN);

*TRISBPtr &= ~(1 << LEDPIN);
*TRISBPtr |= (1 << BUTTONPIN);

*OPTIONPtr |= (1<<6);
*OPTIONPtr &= ~(1<<7);


*INTCONPtr |= (1<<7);
//*INTCONPtr |= (1<<6);
*INTCONPtr |= (1<<4);
*INTCONPtr&=~(1<<1);

while(1){

    }
}


void InterruptHandler(){
	//*TRISBPtr ^= (1 << LEDPIN);
    
    if(*INTCONPtr&=(1<<1)){
        *INTCONPtr^=(1<<LEDPIN);
        *INTCONPtr&=~(1<<1);
    }
}

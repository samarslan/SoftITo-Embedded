//
// Created by Samet Arslan on 27.08.2025.
//

#include <stdint.h>

#define GPIOC_MODER (uint32_t*)0x40020800
#define GPIOB_MODER (uint32_t*)0x40020400
#define GPIOC_ODR (uint32_t*)0x40020814
#define GPIOB_ODR (uint32_t*)0x40020414
#define AHB1ENR (uint32_t*)0x40023830

void delay(){
    for(int i=0;i<1000000;i++);
}

void togglePin(uint32_t* port, int pin){
    *port ^= (1u << pin);
}

void setPin(uint32_t* port, int pin, int logic){
    if(logic)
        *port = *port | (1u << pin);
    else
        *port &= ~(1u<<pin);
}

int main(void) {
    *AHB1ENR |= (1u << 1);
    *AHB1ENR |= (1u << 1);
    for(int i=0; i<31;i=i+2){
        *GPIOC_MODER |= (1u << i);
        *GPIOB_MODER |= (1u << i);
    }
    togglePin(GPIOC_ODR, 12);

    setPin(GPIOB_ODR, 12,1);
}

//
// Created by Samet Arslan on 27.08.2025.
//

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(){
    for(int i=0;i<1000000;i++);
}

void togglePin(uint32_t *port, int pin){
    *port ^= (1u << pin);
}

void setPin(uint32_t *port, int pin, int logic){
    if(logic)
        *port = *port | (1u << pin);
    else
        *port &= ~(1u<<pin);
}


int main(void) {
    volatile uint32_t *pRCCAhb1Enr = (uint32_t)0x40023830;


    volatile uint32_t *pGPIODModer = (uint32_t)0x40020C00;
    *pGPIODModer |= (1u << 24);
    *pGPIODModer |= (1u << 26);
    *pGPIODModer |= (1u << 28);
    *pGPIODModer |= (1u << 30);

    volatile uint32_t *pGPIODODR = (uint32_t)0x40020C14;

    while(1){
        setPin(pGPIODODR, 12, 1);
        setPin(pGPIODODR, 13, 1);
        setPin(pGPIODODR, 14, 1);
        setPin(pGPIODODR, 15, 1);


        delay();
        delay();

        setPin(pGPIODODR, 12, 0);
        setPin(pGPIODODR, 13, 0);
        setPin(pGPIODODR, 14, 0);
        setPin(pGPIODODR, 15, 0);

        delay();
        delay();
    }
}



/*
Ellie Sundheim, esundheim@hmc.edu
9-24-24
This file contains the source code for setting up timers 2 or 3 on the STM32L432KC
*/

#include "STM32L432KC_TIM23.h"

void initTIM(TIM23_TypeDef * TIMx){
  // input the system clock to prescaler by setting SMS[3:0] to 0000
  TIMx->SMCR &= ~(1<<16);
  TIMx->SMCR &= ~(0b111 << 0);

  // set prescale to 19,999 since divide by psc + 1 and want to prescale duration by 20,000 to get CK_CNT at 4 kHz
  TIMx->PSC &= 0;
  TIMx->PSC |= 0b100111000011111;

  // set auto reset register to reset value
  TIMx->ARR = 0xFFFFFFFF;
  
  // enable counter by setting CEN bit in CR1
  TIMx->CR1 |= 1 << 0;

}

void initTIM_PWM(TIM23_TypeDef * TIMx){
  // input the system clock to prescaler by setting SMS[3:0] to 0000
  TIMx->SMCR &= ~(1<<16);
  TIMx->SMCR &= ~(0b111 << 0);

  // set prescale to 799 since divide by psc + 1 to get CK_CNT at 100 kHz
  TIMx->PSC &= 0;
  TIMx->PSC |= 0x31F;

  // set auto reset register to reset value
  TIMx->ARR = 0xFFFFFFFF;
  // set ccr1 arbitrarily (we compare counter to this num, gives us duty cycle) (use equals because we don't want to preserve other bits)
  TIMx->CCR1 = 0x20;

  // select PWM mode 1 (110) by setting OC1M bits (6:4) in TIM2_CCMRx register
  TIMx->CCMR1 |= (0b110 << 4);
  // enable preload register by setting OC1PE bit (3) in CCMRx register
  TIMx->CCMR1 |= (1 << 3);
  // set auto reload preload register ARPE bit (7) in CR1 register
  TIMx->CR1 |= (1 << 7);
  //initialize all registers by setting UG bit (0)in EGR register
  TIMx->EGR |= (1 << 0);
  // enable counter by setting CEN bit (0) in CR1
  TIMx->CR1 |= (1 << 0);

}

void update_freq(TIM23_TypeDef * TIMx, uint32_t newFreq){
  // convert freq to ARR by dividing ck_CNT by new freq
  volatile uint32_t newARR = 80E3 / newFreq;
  TIMx->ARR = newARR;

  //keep duty cycle at 50%
  TIMx->CCR1 = newARR/2;
}

void delay_millis(TIM23_TypeDef *TIMx, uint32_t ms){
  // this function 1) resets the counter then 2) waits until we hit the counter value calculated using the duration and the known freq of timer 3
  TIMx->EGR |= (1 << 0);
  while( TIMx->CNT

}


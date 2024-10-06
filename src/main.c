// lab4_starter.c
// Fur Elise, E155 Lab 4
// Updated Fall 2024
// Ellie Sundheim, esundheim@hmc.edu, 9-24-24

#include "../lib/music.h"
#include "../lib/STM32L432KC_GPIO.h"
#include "../lib/STM32L432KC_RCC.h"
#include "../lib/STM32L432KC_FLASH.h"
#include "../lib/STM32L432KC_TIM23.h"
#include "../lib/STM32L432KC_TIM1516.h"

#define SPEAKER_PIN 3


int main(void) {
    // call configure flash so that the processor can load the insturctions it need before running the clk so fast
    configureFlash();

    // set up overall clock for overall 
    configureClock();
     // turn on clock source for TIM2 (bit 0 is for TIM2)
    RCC->APB1ENR1 |= 1;
    // turn on clock source for TIM15 (bit 16 is for TIM15)
    RCC->APB2ENR |= 1 << 16;
    // turn on clock source for GPIOB
    RCC->AHB2ENR |= (1 << 1);


    //set up tim2 as PWM (100 kHz)
    initTIM_PWM(TIM2);
    //set up tim15 as duration (4 kHz)
    initTIM1516(TIM15);

    //set up gpio (alternate function AF1 on gpioB pin 3)
    pinMode(SPEAKER_PIN, GPIO_ALT);
    GPIO->AFRL |= (0b0001 << 12); //bits 15:12 for pin 3, AF1 is 0001

    // this is just for testing
   // pinMode(SPEAKER_PIN, GPIO_OUTPUT);
   // digitalWrite(SPEAKER_PIN, 1);

    // test continually pwm'ing, PWM clock at 4 khz
    /*update_freq(TIM2, 3); //3 Hz
    while(1){
      delay_millis1516(TIM15, 1000);
    }*/

   //play song
    volatile uint32_t i = 0;

    while (sunshine[i][1] != 0){
      update_freq(TIM2, sunshine[i][0]);
      delay_millis1516(TIM15, sunshine[i][1]);
      i++;
    }
  
    //turn off sound and wait for reset
    update_freq(TIM2, 0);
    while(1){
      }
	
}
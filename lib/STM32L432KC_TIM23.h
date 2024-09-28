// STM32L432KC_TIM23.h
// esundheim@hmc.edu, 9-27-24
// Header for TIM2 and functions

#ifndef STM32L432KC_TIM23_H
#define STM32L432KC_TIM23_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM2_BASE (0x40000000UL) 
#define TIM3_BASE (0x40000400UL)


typedef struct
{
  __IO uint32_t CR1;          /*!< TIM2 control register 1,                                              Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< TIM2 control register 2,                                              Address offset: 0x04 */
  __IO uint32_t SMCR;         /*!< TIM2 slave mode control register,                                     Address offset: 0x08 */
  __IO uint32_t DIER;         /*!< TIM2 DMA interrupt enable register,                                   Address offset: 0x0C */
  __IO uint32_t SR;           /*!< TIM2 status register,                                                 Address offset: 0x10 */
  __IO uint32_t EGR;          /*!< TIM2 event generation register                                        Address offset: 0x14 */
  __IO uint32_t CCMR1;        /*!< TIM2 capture/compare mode register 1,                                 Address offset: 0x18 */
  __IO uint32_t CCMR2;        /*!< TIM2 capture/compare mode register 2,                                 Address offset: 0x1C */
  __IO uint32_t CCER;         /*!< TIM2 capture/compare enable register,                                 Address offset: 0x20 */
  __IO uint32_t CNT;          /*!< TIM2 counter register                                                 Address offset: 0x24 */
  __IO uint32_t PSC;          /*!< TIM2 prescaler register,                                              Address offset: 0x28 */
  __IO uint32_t ARR;          /*!< TIM2 auto reload register,                                            Address offset: 0x2C */
   uint32_t RESERVED;         /*!< Reserved,                                                             Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< TIM2 capture/compare register 1,                                      Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< TIM2 capture/compare register 2,                                      Address offset: 0x38 */
  __IO uint32_t CCR3;         /*!< TIM2 capture/compare register 3,                                      Address offset: 0x3C */
  __IO uint32_t CCR4;         /*!< TIM2 capture/compare register 4,                                      Address offset: 0x40 */
  uint32_t      RESERVED1;    /*!< Reserved,                                                             Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< TIM2 DMA control register,                                            Address offset: 0x48 */
  __IO uint32_t DMAR;         /*!< TIM2 DMA address for full transfer,                                   Address offset: 0x4C */
  __IO uint32_t OR1;          /*!< TIM2 option register 1,                                               Address offset: 0x50 */
  uint32_t RESERVED2;         /*!< Reserved,                                                             Address offset: 0x54 */
  uint32_t RESERVED3;         /*!< Reserved,                                                             Address offset: 0x58 */
  uint32_t RESERVED4;         /*!< Reserved,                                                             Address offset: 0x5C */
  __IO uint32_t OR2;          /*!< TIM2 option register 2,                                               Address offset: 0x60 */
} TIM23_TypeDef;

#define TIM2 ((TIM23_TypeDef *) TIM2_BASE)
#define TIM3 ((TIM23_TypeDef *) TIM3_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////
void initTIM(TIM23_TypeDef * TIMx);
void initTIM_PWM(TIM23_TypeDef * TIMx);
void delay_millis(TIM23_TypeDef * TIMx, uint32_t ms);
void update_duration(TIM23_TypeDef * TIMx, uint32_t newDur);
void update_freq(TIM23_TypeDef* TIMx, uint32_t newFreq);



#endif
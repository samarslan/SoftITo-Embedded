//
// Created by Samet Arslan on 12.09.2025.
//
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define DHT11_PORT GPIOC
#define DHT11_PIN GPIO_PIN_1

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */
volatile uint8_t relativeHumidityIntegral = 0;
volatile uint8_t relativeHumidityDecimal = 0;
volatile uint8_t tempretureIntegral = 0;
volatile uint8_t tempretureDecimal = 0;
volatile uint8_t readChecksum = 0;
volatile uint8_t calculatedChecksum = 0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM6_Init(void);
/* USER CODE BEGIN PFP */

void TIM2_Delay_us(uint16_t us);
void DHT11_SetPinOutput(void);
void DHT11_SetLogicHigh(void);
void DHT11_SetLogicLow(void);
void DHT11_SetPinInput(void);
uint8_t DHT11_ReadByte(void);
void DHT11_Read(void);
GPIO_PinState DHT11_GetPinRead(void);


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_TIM_Base_Start(&htim6);
  while (1)
  {
	  DHT11_Read();
	  HAL_Delay(10000);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 83;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 65535;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin : PC1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void TIM6_Delay_us(volatile uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us){
    	;
    }
}
// PC1 is pin 1 of GPIOC

// Set PC1 as output (push-pull, no pull-up/pull-down)
// PC1 is pin 1 of GPIOC

// Set PC1 as output (push-pull, no pull-up/pull-down)
void DHT11_SetPinOutput(void) {
    // MODER: 2 bits per pin, 01 = output
    GPIOC->MODER &= ~(0x3 << (1 * 2)); // clear bits
    GPIOC->MODER |=  (0x1 << (1 * 2)); // set as output

    // OTYPER: 0 = push-pull
    GPIOC->OTYPER &= ~(1 << 1);

    // PUPDR: 00 = no pull-up/pull-down
    GPIOC->PUPDR &= ~(0x3 << (1 * 2));
}

// Set PC1 as input (no pull-up/pull-down)
void DHT11_SetPinInput(void) {
    // MODER: 00 = input
    GPIOC->MODER &= ~(0x3 << (1 * 2));

    // PUPDR: 00 = no pull
    GPIOC->PUPDR &= ~(0x3 << (1 * 2));
}

// Set PC1 high
void DHT11_SetLogicHigh(void) {
    GPIOC->BSRR = (1 << 1);  // set bit
}

// Set PC1 low
void DHT11_SetLogicLow(void) {
    GPIOC->BSRR = (1 << (1 + 16)); // reset bit
}

// Read PC1
GPIO_PinState DHT11_GetPinRead(void) {
    return (GPIOC->IDR & (1 << 1)) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}


uint8_t DHT11_ReadByte(void) {
    uint8_t i, byte = 0;
    for (i = 0; i < 8; i++) {
        uint32_t timeout = 0;
        while (!(GPIOC->IDR & (1 << 1))) {
            if (++timeout > 10000) return 0;
        }

        // Wait ~40 us to sample bit
        TIM6_Delay_us(40);

        // Read bit value
        if (GPIOC->IDR & (1 << 1)) {
            byte |= (1 << (7 - i));
        }

        timeout = 0;
        while (GPIOC->IDR & (1 << 1)) {
            if (++timeout > 10000) break;
        }
    }
    return byte;
}

void DHT11_Read(void){
    uint8_t rh_int, rh_dec, t_int, t_dec, checksum;


    DHT11_SetPinInput();
    HAL_Delay(18);
    DHT11_SetPinOutput();
    DHT11_SetLogicHigh();
    TIM6_Delay_us(20);

    DHT11_SetPinInput();

    uint32_t timeout = 0;
    while (GPIOC->IDR & (1 << 1)) { if (++timeout > 10000) return; }
    timeout = 0;
    while (!(GPIOC->IDR & (1 << 1))) { if (++timeout > 10000) return; }
    timeout = 0;
    while (GPIOC->IDR & (1 << 1)) { if (++timeout > 10000) return; }

    rh_int = DHT11_ReadByte();
    rh_dec = DHT11_ReadByte();
    t_int  = DHT11_ReadByte();
    t_dec  = DHT11_ReadByte();
    checksum = DHT11_ReadByte();

    if (checksum == (rh_int + rh_dec + t_int + t_dec)) {
        relativeHumidityIntegral = rh_int;
        relativeHumidityDecimal = rh_dec;
        tempretureIntegral = t_int;
        tempretureDecimal = t_dec;
        readChecksum = checksum;
    } else {

    }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

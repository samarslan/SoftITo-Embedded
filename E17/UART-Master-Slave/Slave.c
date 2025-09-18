//
// Created by Samet Arslan on 18.09.2025.
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
#include <string.h>
#include <stdint.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define MAX_TOKEN_LENGTH 4
#define NUMBER_OF_TOKENS_IN_A_PACKET 3
#define MAX_PACKET_LENGTH 18

#define MAX_TIMEOUT_MS 1000

#define ALL 0
#define X 1
#define Y 2

#define OFF 0
#define ON 1
#define GET 2


/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart4;

/* USER CODE BEGIN PV */
char leds[3][MAX_TOKEN_LENGTH] = {"ALL", "X", "Y"};
char commands[3][MAX_TOKEN_LENGTH]={"OFF","ON","GET"};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);
/* USER CODE BEGIN PFP */
void ParseData(char* data);
void TokenHandler(char tokens[NUMBER_OF_TOKENS_IN_A_PACKET][MAX_TOKEN_LENGTH]);

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
  MX_UART4_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  char data[MAX_PACKET_LENGTH] = "\0";

//  char data[] = "abc-def-ghi";
  while (1)
  {
	  HAL_StatusTypeDef uartStatus = HAL_UART_Receive(&huart4, (uint8_t*)data, MAX_PACKET_LENGTH, MAX_TIMEOUT_MS);

	  if(uartStatus == HAL_OK){
		  ParseData(data);
	      memset(data, 0, MAX_PACKET_LENGTH);
	  }


/*  if(data[0]!='\0'){
	  ParseData(data);
  }*/

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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_2;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void PacketBuilder(char *packet, const char *packetHeader, uint8_t led, uint8_t command) {
    packet[0] = '\0';

    strcat(packet, packetHeader);
    strcat(packet, "-");
    strcat(packet, leds[led]);
    strcat(packet, "-");
    strcat(packet, commands[command]);
    strcat(packet, "\r\n");
}


void SetLed(const uint8_t led, const uint8_t logicLevel) {
    char *packetHeader = "LED";
    char packet[MAX_PACKET_LENGTH];

    PacketBuilder(packet, packetHeader, led, logicLevel);

    HAL_UART_Transmit(&huart4, (uint8_t*)packet, strlen(packet), MAX_TIMEOUT_MS);
}

uint8_t IsLedOn(uint16_t pin) {
    return HAL_GPIO_ReadPin(GPIOD, pin) == GPIO_PIN_SET;
}

void LedHandler(char* led, char* instruction) {
    if (strcmp(instruction, "GET") == 0) {
        if (strcmp(led, "ALL") == 0) {
            uint8_t xOn = IsLedOn(GPIO_PIN_13);
            uint8_t yOn = IsLedOn(GPIO_PIN_14);

            char packet[MAX_PACKET_LENGTH];

            if (xOn && yOn) {
                PacketBuilder(packet, "LED", ALL, ON);
            } else if (xOn) {
                PacketBuilder(packet, "LED", X, ON);
            } else if (yOn) {
                PacketBuilder(packet, "LED", Y, ON);
            } else {
                PacketBuilder(packet, "LED", ALL, OFF);
            }

            HAL_UART_Transmit(&huart4, (uint8_t*)packet, strlen(packet), MAX_TIMEOUT_MS);
        }
    }
    else if (strcmp(instruction, "ON") == 0) {
        if (strcmp(led, "ALL") == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
        } else if (strcmp(led, "X") == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
        } else if (strcmp(led, "Y") == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
        }
    }
    else if (strcmp(instruction, "OFF") == 0) {
        if (strcmp(led, "ALL") == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
        } else if (strcmp(led, "X") == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
        } else if (strcmp(led, "Y") == 0) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        }
    }
}


void TokenHandler(char tokens[NUMBER_OF_TOKENS_IN_A_PACKET][MAX_TOKEN_LENGTH]){
    if(strcmp(tokens[0], "LED") == 0){
    	LedHandler(tokens[1],tokens[2]);
    }
}

void ParseData(char* data) {
    char tokens[NUMBER_OF_TOKENS_IN_A_PACKET][MAX_TOKEN_LENGTH];
    char* token;
    int i = 0;

    token = strtok(data, "-\r\n");
    while(token != NULL && i < NUMBER_OF_TOKENS_IN_A_PACKET) {
        strncpy(tokens[i], token, MAX_TOKEN_LENGTH-1);
        tokens[i][MAX_TOKEN_LENGTH-1] = '\0';
        i++;
        token = strtok(NULL, "-\r\n");
    }
    TokenHandler(tokens);
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

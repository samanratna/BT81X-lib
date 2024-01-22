/*
 * Copyright (c) Riverdi Sp. z o.o. sp. k. <riverdi@riverdi.com>
 * Copyright (c) Skalski Embedded Technologies <contact@lukasz-skalski.com>
 */

#include "platform.h"
#include "main.h"

/*
 * platform_init()
 */
bool_t platform_init(Gpu_HalInit_t *halinit) {

	return TRUE;
}

/*
 * platform_sleep_ms()
 */
void platform_sleep_ms(uint32_t ms) {
	HAL_Delay(ms);
}

/*
 * platform_spi_init()
 */
bool_t platform_spi_init(Gpu_Hal_Context_t *host) {
		return TRUE;
}

/*
 * platform_spi_deinit()
 */
void platform_spi_deinit(Gpu_Hal_Context_t *host) {
	HAL_SPI_DeInit(&hspi1);
}

/*
 * platform_spi_send_recv_byte();
 */
uchar8_t platform_spi_send_recv_byte(Gpu_Hal_Context_t *host, uchar8_t data,
		uint32_t opt) {
	uint8_t answer;

	HAL_SPI_TransmitReceive(&hspi1, &data, &answer, 1, HAL_MAX_DELAY);

	return answer;
}

/*
 * platform_spi_send_data()
 */
uint16_t platform_spi_send_data(Gpu_Hal_Context_t *host, uchar8_t *data,
		uint16_t size, uint32_t opt) {
	HAL_SPI_Transmit(&hspi1, data, size, HAL_MAX_DELAY);

	return size;
}

/*
 * platform_spi_recv_data()
 */
void platform_spi_recv_data(Gpu_Hal_Context_t *host, uchar8_t *data,
		uint16_t size, uint32_t opt) {
	HAL_SPI_Receive(&hspi1, data, size, HAL_MAX_DELAY);
}

/*
 * platform_gpio_init()
 */
bool_t platform_gpio_init(Gpu_Hal_Context_t *host, gpio_name ngpio) {
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = ngpio;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOA, &gpio);

	return TRUE;
}

/*
 * platform_gpio_value()
 */
bool_t platform_gpio_value(Gpu_Hal_Context_t *host, gpio_name ngpio,
		gpio_val vgpio) {
	HAL_GPIO_WritePin(GPIOA, ngpio, vgpio);
	return TRUE;
}

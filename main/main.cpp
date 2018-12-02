// ESP32 RMT module demonstration with WS2811/WS2812 LEDs.
//
// The WS2812 with the RMT module driver is by pcbreflux: https://github.com/pcbreflux/espressif/tree/master/esp32/app/ESP32_gpio_WS2812   
//
// Some modifications have been made on the ws2812_task.cpp: Most of the color changing functions has no. of loops that can be now determined by user.
// Longer loops -> color changing functions runs longer time, and shorter loops -> color changing functions runs shorter time.
//
// Added some functions that are taken from another of my project: https://github.com/uncle-yong/sk1632-ws2812-christmas
//
// This project also uses WS2811 - it uses the RGB configuration instead of GRB.
/* 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>. *
 */
#include <string.h>
#include <stdlib.h>

#include "sdkconfig.h"
#include "nvs_flash.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "freertos/heap_regions.h"

#include "esp_log.h"
#include "esp_system.h"
#include "esp_heap_alloc_caps.h"

#include "ws2812_task.h"

#define TAG "MAIN"

extern "C" void app_main(void) {

    nvs_flash_init();

    xTaskCreate(ws2812_task, "gpio_task", 12288, NULL, 5, NULL);
    
    while(1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    };

}


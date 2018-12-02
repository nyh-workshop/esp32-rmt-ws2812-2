# esp32-rmt-ws2812-2

## ESP32 RMT module demonstration with WS2811/WS2812 LEDs.

The WS2812 with the RMT module driver is by pcbreflux: https://github.com/pcbreflux/espressif/tree/master/esp32/app/ESP32_gpio_WS2812   
Some modifications have been made on the ws2812_task.cpp which is most of the color changing functions has no. of loops that can be now determined by user.

Longer loops -> color changing functions runs longer time, and shorter loops -> color changing functions runs shorter time.

Added some functions that are taken from another of my project: https://github.com/uncle-yong/sk1632-ws2812-christmas

This project also uses WS2811 - it uses the RGB configuration instead of GRB.

Connect pin 17 to the data pin (DIN) on the WS2811/WS2812.

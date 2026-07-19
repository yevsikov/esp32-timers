#include <Arduino.h>
#define LED_PIN 5

constexpr uint32_t PERIOD = 20;      // для тестування (20 секунд)
constexpr uint32_t WORK_TIME = 5;    // працює 5 секунди

hw_timer_t* timer = nullptr;

volatile bool secondTick = false;
uint32_t seconds = 0;

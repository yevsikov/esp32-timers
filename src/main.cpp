#include <Arduino.h>
#define LED_PIN 5

constexpr uint32_t PERIOD = 20;      // для тестування (20 секунд)
constexpr uint32_t WORK_TIME = 5;    // працює 5 секунди

hw_timer_t* timer = nullptr;

volatile bool secondTick = false;
uint32_t seconds = 0;

void IRAM_ATTR onTimer() {
    secondTick = true;
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    timer = timerBegin(1000000);
    timerAttachInterrupt(timer, &onTimer);
    timerAlarm(timer, 1000000, true, 0);
}


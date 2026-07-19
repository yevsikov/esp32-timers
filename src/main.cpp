#include <Arduino.h>
#define RELAY_PIN 5

constexpr uint32_t PERIOD = 20;      // for testing (20 seconds)
constexpr uint32_t WORK_TIME = 5;    // work 5 seconds

hw_timer_t* timer = nullptr;

volatile bool secondTick = false;
uint32_t seconds = 0;

void IRAM_ATTR onTimer() {
    secondTick = true;
}

void setup() {
    Serial.begin(115200);
    pinMode(RELAY_PIN, OUTPUT);

    timer = timerBegin(1000000);
    timerAttachInterrupt(timer, &onTimer);
    timerAlarm(timer, 1000000, true, 0);
}


void loop() {
  if (secondTick) {
    secondTick = false;
    seconds++;

    if ((seconds % PERIOD) < WORK_TIME) {
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Fan ON");
    } else {
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("Fan OFF");
    }
  }
}
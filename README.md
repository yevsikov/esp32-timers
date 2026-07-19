# ESP32 Timers - Learning Project

This is a small educational project for the [Embedded Development course](https://beetroot.academy/courses/online/kurs-embedded-development)

## Circuit Diagram

```
ESP32-S3
────────┐             ┌─────────────────────┐
        |             |                     |
GPIO5   |-------------| IN                  |
GND     |-------------| GND                 |
3.3V    |-------------| VCC                 |
────────┘             |                     |
                      |     Relay Module    |
                      |                     |
                      | COM    NO      NC   |
                      └──┬─────┬───────┬────┘
                         |     |
                         |     |
         +3.3V ----------┘     |                      LED Indicator
 (External power source)       +--------------------------|>|----------[R220Om]------GND
                               |
                           ┌───┴────────────────┐
                           | MOTOR   with FAN   |
                           └───┬────────────────┘
                               │
                               │
                               +-------------------------------+
                               |                               |
                               |                               |
                               |                               |
                               |          (flyback diode)      |
                               +--------------|<|--------------+
                               |
                              GND
                               |
                               |
GND (External) ----------------+
                               |
                               |
ESP32 GND ---------------------+

```


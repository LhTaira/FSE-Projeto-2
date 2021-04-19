#ifndef GPIO_H
#define GPIO_H

#define PIN_LAMPADA_1 11
#define PIN_LAMPADA_2 12
#define PIN_LAMPADA_3 13
#define PIN_LAMPADA_4 15

#define PIN_AR_CONDICIONADO_1 33
#define PIN_AR_CONDICIONADO_2 35

#define PIN_PRESENCA_1 22
#define PIN_PRESENCA_2 37

#define PIN_ABERTURA_1 29
#define PIN_ABERTURA_2 31
#define PIN_ABERTURA_3 32
#define PIN_ABERTURA_4 36
#define PIN_ABERTURA_5 38
#define PIN_ABERTURA_6 40

#include <softPwm.h>
#include <unistd.h>
#include <wiringPi.h>

#include "global.hpp"

using namespace std;

void update_all_sensors();
bool read_pin(int pin);
void set_pin_modes();
void write_pin(int pin, int value);

#endif
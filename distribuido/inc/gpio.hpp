#ifndef GPIO_H
#define GPIO_H

#define PIN_LAMPADA_1 17
#define PIN_LAMPADA_2 18
#define PIN_LAMPADA_3 27
#define PIN_LAMPADA_4 22

#define PIN_AR_CONDICIONADO_1 13
#define PIN_AR_CONDICIONADO_2 19

#define PIN_PRESENCA_1 25
#define PIN_PRESENCA_2 26

#define PIN_ABERTURA_1 5
#define PIN_ABERTURA_2 6
#define PIN_ABERTURA_3 12
#define PIN_ABERTURA_4 16
#define PIN_ABERTURA_5 20
#define PIN_ABERTURA_6 21

#include <softPwm.h>
#include <unistd.h>
#include <wiringPi.h>

#include "global.hpp"

using namespace std;

void update_all_sensors();
bool read_pin(int pin);

void write_pin(int pin, bool value);

#endif
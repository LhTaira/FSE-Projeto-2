#ifndef GPIO_H
#define GPIO_H

#define PIN_LAMPADA_1 0
#define PIN_LAMPADA_2 1
#define PIN_LAMPADA_3 2
#define PIN_LAMPADA_4 3

#define PIN_AR_CONDICIONADO_1 23
#define PIN_AR_CONDICIONADO_2 24

#define PIN_PRESENCA_1 6
#define PIN_PRESENCA_2 25

#define PIN_ABERTURA_1 21
#define PIN_ABERTURA_2 22
#define PIN_ABERTURA_3 26
#define PIN_ABERTURA_4 27
#define PIN_ABERTURA_5 28
#define PIN_ABERTURA_6 29


#include <softPwm.h>
#include <unistd.h>
#include <wiringPi.h>

#include "client.hpp"
#include "global.hpp"

using namespace std;

void update_and_setup();
bool read_pin(int pin);
void set_pin_modes();
void write_pin(int pin, int value);

void watch_ab1(void);
void watch_ab2(void);
void watch_ab3(void);
void watch_ab4(void);
void watch_ab5(void);
void watch_ab6(void);

void watch_pr1(void);
void watch_pr2(void);

void setup_watchers();

#endif
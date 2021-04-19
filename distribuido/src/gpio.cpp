#include "../inc/gpio.hpp"

using namespace std;

bool read_pin(int pin) { return (bool)digitalRead(pin); }

void update_all_sensors()
{
  presenca[0] = read_pin(PIN_PRESENCA_1);
  presenca[1] = read_pin(PIN_PRESENCA_2);

  abertura[0] = read_pin(PIN_ABERTURA_1);
  abertura[1] = read_pin(PIN_ABERTURA_2);
  abertura[2] = read_pin(PIN_ABERTURA_3);
  abertura[3] = read_pin(PIN_ABERTURA_4);
  abertura[4] = read_pin(PIN_ABERTURA_5);
  abertura[5] = read_pin(PIN_ABERTURA_6);
}

void set_pin_modes()
{
  pinMode(PIN_LAMPADA_1, OUTPUT);
  pinMode(PIN_LAMPADA_2, OUTPUT);
  pinMode(PIN_LAMPADA_3, OUTPUT);
  pinMode(PIN_LAMPADA_4, OUTPUT);
  pinMode(PIN_AR_CONDICIONADO_1, OUTPUT);
  pinMode(PIN_AR_CONDICIONADO_2, OUTPUT);
}

void write_pin(int pin, int value)
{
  digitalWrite(pin, value);
  usleep(10000);
}
#include "../inc/gpio.hpp"

using namespace std;

bool read_pin(int pin) { return (bool)digitalRead(pin); }

void update_and_setup() {
  watch_pr1();
  watch_pr2();
  watch_ab1();
  watch_ab2();
  watch_ab3();
  watch_ab4();
  watch_ab5();
  watch_ab6();

  write_pin(PIN_AR_CONDICIONADO_1, 0);
  write_pin(PIN_AR_CONDICIONADO_2, 0);

  write_pin(PIN_LAMPADA_1, 0);
  write_pin(PIN_LAMPADA_2, 0);
  write_pin(PIN_LAMPADA_3, 0);
  write_pin(PIN_LAMPADA_4, 0);

  for(int i=0; i<4; i++) {
    lampada[i] = false;
  }

  for(int i=0; i<2; i++) {
    arCondicionado[i] = false;
  }
}

void set_pin_modes() {
  pinMode(PIN_PRESENCA_1, INPUT);
  pinMode(PIN_PRESENCA_2, INPUT);
  pinMode(PIN_ABERTURA_1, INPUT);
  pinMode(PIN_ABERTURA_2, INPUT);
  pinMode(PIN_ABERTURA_3, INPUT);
  pinMode(PIN_ABERTURA_4, INPUT);
  pinMode(PIN_ABERTURA_5, INPUT);
  pinMode(PIN_ABERTURA_6, INPUT);

  pinMode(PIN_LAMPADA_1, OUTPUT);
  pinMode(PIN_LAMPADA_2, OUTPUT);
  pinMode(PIN_LAMPADA_3, OUTPUT);
  pinMode(PIN_LAMPADA_4, OUTPUT);
  pinMode(PIN_AR_CONDICIONADO_1, OUTPUT);
  pinMode(PIN_AR_CONDICIONADO_2, OUTPUT);
}

void write_pin(int pin, int value) {
  digitalWrite(pin, value);
  usleep(10000);
}
void watch_ab1(void) {
  if (read_pin(PIN_ABERTURA_1)) {
    send_message(ip_central, porta_central, "A1t");
  } else {
    send_message(ip_central, porta_central, "ab1f");
  }
  wiringPiISR(PIN_ABERTURA_1, INT_EDGE_BOTH, &watch_ab1);
  return;
}

void watch_ab2(void) {
  if (read_pin(PIN_ABERTURA_2)) {
    send_message(ip_central, porta_central, "A2t");
  } else {
    send_message(ip_central, porta_central, "A2f");
  }

  wiringPiISR(PIN_ABERTURA_2, INT_EDGE_BOTH, &watch_ab2);
  return;
}

void watch_ab3(void) {
  if (read_pin(PIN_ABERTURA_3)) {
    send_message(ip_central, porta_central, "A3t");
  } else {
    send_message(ip_central, porta_central, "A3f");
  }

  wiringPiISR(PIN_ABERTURA_3, INT_EDGE_BOTH, &watch_ab3);
  return;
}

void watch_ab4(void) {
  if (read_pin(PIN_ABERTURA_4)) {
    send_message(ip_central, porta_central, "A4t");
  } else {
    send_message(ip_central, porta_central, "A4f");
  }

  wiringPiISR(PIN_ABERTURA_4, INT_EDGE_BOTH, &watch_ab4);
  return;
}

void watch_ab5(void) {
  if (read_pin(PIN_ABERTURA_5)) {
    send_message(ip_central, porta_central, "A5t");
  } else {
    send_message(ip_central, porta_central, "A5f");
  }

  wiringPiISR(PIN_ABERTURA_5, INT_EDGE_BOTH, &watch_ab5);
  return;
}

void watch_ab6(void) {
  if (read_pin(PIN_ABERTURA_6)) {
    send_message(ip_central, porta_central, "A6t");
  } else {
    send_message(ip_central, porta_central, "A6f");
  }

  wiringPiISR(PIN_ABERTURA_6, INT_EDGE_BOTH, &watch_ab6);
  return;
}

void watch_pr1(void) {
  if (read_pin(PIN_PRESENCA_1)) {
    send_message(ip_central, porta_central, "P1t");
  } else {
    send_message(ip_central, porta_central, "P1f");
  }
  wiringPiISR(PIN_PRESENCA_1, INT_EDGE_BOTH, &watch_pr1);
  return;
}
void watch_pr2(void) {
  if (read_pin(PIN_PRESENCA_2)) {
    send_message(ip_central, porta_central, "P2t");
  } else {
    send_message(ip_central, porta_central, "P2f");
  }
  wiringPiISR(PIN_PRESENCA_2, INT_EDGE_BOTH, &watch_pr2);
  return;
}

void setup_watchers() {
  wiringPiISR(PIN_PRESENCA_1, INT_EDGE_BOTH, &watch_pr1);
  wiringPiISR(PIN_PRESENCA_2, INT_EDGE_BOTH, &watch_pr2);

  wiringPiISR(PIN_ABERTURA_1, INT_EDGE_BOTH, &watch_ab1);
  wiringPiISR(PIN_ABERTURA_2, INT_EDGE_BOTH, &watch_ab2);
  wiringPiISR(PIN_ABERTURA_3, INT_EDGE_BOTH, &watch_ab3);
  wiringPiISR(PIN_ABERTURA_4, INT_EDGE_BOTH, &watch_ab4);
  wiringPiISR(PIN_ABERTURA_5, INT_EDGE_BOTH, &watch_ab5);
  wiringPiISR(PIN_ABERTURA_6, INT_EDGE_BOTH, &watch_ab6);
}
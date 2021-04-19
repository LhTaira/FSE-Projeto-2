#include <string.h>
#include <time.h>
#include <wiringPi.h>
// #include <signal.h>

#include <iostream>
#include <string>
#include <thread>

#include "../inc/bme280.hpp"
#include "../inc/client.hpp"
#include "../inc/global.hpp"
#include "../inc/gpio.hpp"
#include "../inc/server.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  // signal(SIGPIPE, SIG_IGN);
  bme280Init(1, 0x76);
  wiringPiSetupGpio();
  set_pin_modes();

  if (!string("-h").compare(argv[1]) || argc != 4) {
    cout << "Uso: ./bin/bin <Porta para ouvir> <IP servidor central> <Porta "
            "servidor central>"
         << endl;
    exit(0);
  }

  porta_ouvir = (unsigned short)atoi(argv[1]);
  ip_central = string(argv[2]);
  porta_central = (unsigned short)atoi(argv[3]);

  thread t(server, porta_ouvir);

  time_t timer, timer2;
  time(&timer);
  while (1) {
    time(&timer2);
    while (timer == time(&timer2)) {
      usleep(10000);
    }
    time(&timer);

    get_bme();
    update_all_sensors();
    make_and_send_message(ip_central, porta_central);
    make_temperature_humidity_message(ip_central, porta_central);
  }
}
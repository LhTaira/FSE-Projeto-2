#include <string.h>
#include <time.h>

#include <iostream>
#include <string>
#include <thread>

#include "client.hpp"
#include "server.hpp"
#include "global.hpp"

using namespace std;

int main(int argc, char *argv[]) {
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
      usleep(100);
    }
    time(&timer);

    if ((timer % 2) == 0) {
      for (int i = 0; i < 6; i++) {
        abertura[i] = true;
      }
    } else {
      for (int i = 0; i < 6; i++) {
        abertura[i] = false;
      }
    }
    make_and_send_message(ip_central, porta_central);
  }
}
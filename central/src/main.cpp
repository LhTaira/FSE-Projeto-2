#include <time.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <thread>

#include "../inc/global.hpp"
#include "../inc/menu.hpp"
#include "../inc/server.hpp"
#include "../inc/alarm.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (!string("-h").compare(argv[1]) || argc != 4) {
    cout << "Uso: ./bin/bin <Porta para ouvir> <IP servidor distribuido> "
            "<Porta servidor distribuido>"
         << endl;
    exit(0);
  }

  porta_ouvir = (unsigned short)atoi(argv[1]);
  ip_distribuido = string(argv[2]);
  porta_distribuido = (unsigned short)atoi(argv[3]);

  thread t(server, porta_ouvir);

  //signal verify_alarm
  doMenu();

  // while (true) {
  //   cout << temperatura << endl;
  //   cout << umidade << endl << endl;
  //   sleep(1);
  // }

  exit(0);
}
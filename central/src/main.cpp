#include <time.h>
#include <unistd.h>

#include <iostream>
#include <thread>
#include <string>

#include "../inc/server.hpp"
#include "../inc/global.hpp"
#include "../inc/menu.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if(!string("-h").compare(argv[1]) || argc != 4) {
    cout << "Uso: ./bin/bin <Porta para ouvir> <IP servidor distribuido> <Porta servidor distribuido>" <<  endl;
    exit(0);
  }

  porta_ouvir = (unsigned short) atoi(argv[1]);
  ip_distribuido = string(argv[2]);
  porta_distribuido = (unsigned short) atoi(argv[3]);

  thread t(server, porta_ouvir);
  doMenu();
  exit(0);
}
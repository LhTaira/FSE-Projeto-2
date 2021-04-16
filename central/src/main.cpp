#include <time.h>
#include <unistd.h>

#include <iostream>
#include <thread>

#include "../inc/server.hpp"
#include "../inc/global.hpp"
#include "../inc/menu.hpp"

// void server(char *one, char *two, char *three) {
//   time_t timer3;
//   time(&timer3);
//   while (1) {
//     time_t timer4;
//     while (time(&timer4) == timer3) {
//       usleep(100);
//     }
//     time(&timer3);

//     if ((timer3 % 2) == 0) {
//       for (int i = 0; i < 2; i++) {
//         arCondicionado[i] = "desligado";
//         lampada[i] = "desligada";
//         presenca[i] = "desligado";
//       }

//       for (int i = 0; i < 6; i++) {
//         abertura[i] = "desligado";
//       }

//       alarme = "desligado";
//     } else {
//       for (int i = 0; i < 2; i++) {
//         arCondicionado[i] = "Ligado";
//         lampada[i] = "Ligado";
//         presenca[i] = "Ligado";
//       }

//       for (int i = 0; i < 6; i++) {
//         abertura[i] = "Ligado";
//       }

//       alarme = "Ligado";
//     }
//   }
// }

using namespace std;

int main(int argc, char *argv[]) {
  thread t(server, (unsigned short) atoi(argv[1]));
  doMenu();
  exit(0);
}
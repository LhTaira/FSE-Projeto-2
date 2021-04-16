#include <iostream>
#include <time.h>
#include <string.h>

#include "client.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    time_t timer, timer2;
    time(&timer);
    while(1) {
        time(&timer2);
        while(timer == time(&timer2)) {
            usleep(100);
        }
        time(&timer);

        if ((timer % 2) == 0) {
            send_message((string) argv[1], (unsigned short) atoi(argv[2]), (string) "Ligado");
        } else {
            send_message((string) argv[1], (unsigned short) atoi(argv[2]), (string) "Desligado");
        }

    }
}
#ifndef CLIENTDIST_H
#define CLIENTDIST_H

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

void make_and_send_message(string IP_servidor, unsigned short servidorPorta);
void make_temperature_humidity_message(string IP_servidor, unsigned short servidorPorta);
bool send_message(string IP_Servidor, unsigned short servidorPorta, string mensagem);

#endif
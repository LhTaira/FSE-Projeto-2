#ifndef SERVERDIST_H
#define SERVERDIST_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

#include "global.hpp"
#include "gpio.hpp"

using namespace std;

void TrataClienteTCP(int socketCliente);
void server(unsigned short servidorPorta);

#endif
#ifndef CLIENCENT_H
#define CLIENCENT_H

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;

bool send_message(string IP_Servidor, unsigned short servidorPorta, string mensagem);

#endif
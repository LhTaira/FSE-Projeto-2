#ifndef SERVERCENT_H
#define SERVERCENT_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>

#include <iostream>

#include "global.hpp"

using namespace std;

void server(unsigned short servidorPorta);

#endif
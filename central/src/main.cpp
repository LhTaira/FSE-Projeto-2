#include <time.h>
#include <unistd.h>

#include <iostream>
#include <thread>

#include "../inc/server.hpp"
#include "../inc/global.hpp"
#include "../inc/menu.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  thread t(server, (unsigned short) atoi(argv[1]));
  doMenu();
  exit(0);
}
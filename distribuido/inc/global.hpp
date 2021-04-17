#ifndef GLOBALDIST_H
#define GLOBALDIST_H
#include <string>

using namespace std;

extern bool arCondicionado[2];
extern bool lampada[2];
extern bool presenca[2];
extern bool abertura[6];
extern bool alarme;

extern unsigned short porta_ouvir;
extern string ip_central;
extern unsigned short porta_central;

extern float temperatura;
extern float umidade;

#endif
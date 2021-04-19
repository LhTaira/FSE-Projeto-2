#ifndef GLOBALCENT_H
#define GLOBALCENT_H
#include <string>
 #include <unistd.h>

using namespace std;


extern string arCondicionado[2];
extern string lampada[4];
extern string presenca[2];
extern string abertura[6];
extern string alarme;
extern bool sound_alarm;
extern bool previous_sound_alarm;


extern string temperatura;
extern string umidade;

extern unsigned short porta_ouvir;
extern string ip_distribuido;
extern unsigned short porta_distribuido;


#endif
#include <../inc/global.hpp>

using namespace std;


pid_t this_pid = getpid();
string arCondicionado[2];
string lampada[4];
string presenca[2];
string abertura[6];
string alarme;
bool sound_alarm = false;
bool previous_sound_alarm = false;

string temperatura;
string umidade;

unsigned short porta_ouvir;
string ip_distribuido;
unsigned short porta_distribuido;

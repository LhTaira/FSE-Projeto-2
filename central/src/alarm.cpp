#include "../inc/alarm.hpp"

using namespace std;

void actually_play() {
  try {
      system("aplay alarm.mp3 > /dev/null 2>&1");
    } catch (...) {
    }
}

void verify_alarm() {
  string ligado("Ligado");
  if (ligado.compare(alarme) == 0) {
    sound_alarm = false;
    for (int i = 0; i < 2; i++) {
      if (ligado.compare(presenca[i]) == 0) {
        sound_alarm = true;
      }
    }

    for (int i = 0; i < 6; i++) {
      if (ligado.compare(abertura[i]) == 0) {
        sound_alarm = true;
      }
    }
  } else {
    sound_alarm = false;
  }

  if (sound_alarm) {
    thread(actually_play).detach();
    log_event("alarme_disparado");
  }
}
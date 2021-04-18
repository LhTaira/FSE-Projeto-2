#include "../inc/alarm.hpp"

void verify_alarm() {
  if (alarme) {
    sound_alarm = false;
    for (int i = 0; i < 2; i++) {
      if (presenca[i]) {
        sound_alarm = true;
      }
    }

    for (int i = 0; i < 6; i++) {
      if (abertura[i]) {
        sound_alarm = true;
      }
    }

  } else {
    sound_alarm = false;
  }

  if (sound_alarm && !previous_sound_alarm) {
    // set_off_alarm
    log("alarme_disparado");
  } else if (!sound_alarm && previous_sound_alarm)
  {
    //turn_off_alarm
  }

  previous_sound_alarm = sound_alarm;
}
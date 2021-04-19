#include "../inc/alarm.hpp"

void verify_alarm(int sig)
{
  string ligado("Ligado");
  if (ligado.compare(alarme) == 0)
  {
    sound_alarm = false;
    for (int i = 0; i < 2; i++)
    {
      if (ligado.compare(presenca[i]) == 0)
      {
        sound_alarm = true;
      }
    }

    for (int i = 0; i < 6; i++)
    {
      if (ligado.compare(abertura[i]) == 0)
      {
        sound_alarm = true;
      }
    }
  }
  else
  {
    sound_alarm = false;
  }

  if (sound_alarm && !previous_sound_alarm)
  {
    // set_off_alarm
    try
    {
      system("omxplayer alarm.mp3")
    }
    catch (...)
    {
    }
    log_event("alarme_disparado");
  }
  else if (!sound_alarm && previous_sound_alarm)
  {
    //turn_off_alarm
  }

  previous_sound_alarm = sound_alarm;
}
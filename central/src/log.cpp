#include "../inc/log.hpp"

using namespace std;

void createLog() {
  FILE *log;
  log = fopen("log.csv", "w");
  fseek(log, 0, SEEK_END);
  int size = ftell(log);
  if (size == 0) {
    fprintf(log, "d-m-yyyy h:m:s,tipo_de_evento\n");
  }
  fclose(log);
}

void log_event(string log_message) {
  struct tm *dateTime;
  time_t seconds;
  time(&seconds);
  FILE *log;
  dateTime = localtime(&seconds);
  log = fopen("log.csv", "a");

  fprintf(log, "%d-%d-%d %d:%d:%d,%s\n", dateTime->tm_mday,
          dateTime->tm_mon + 1, dateTime->tm_year + 1900, dateTime->tm_hour,
          dateTime->tm_min, dateTime->tm_sec, log_message.c_str());
  fclose(log);
}
#ifndef MENU_H
#define MENU_H

#include <form.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <time.h>
#include "../inc/socket.hpp"
#include "../inc/client.hpp"


extern int startx;
extern int starty;
extern int choice;
extern WINDOW* menu_win;
// extern char* choices;
extern int n_choices;
extern time_t timer, timer2;

void print_menu(WINDOW* menu_win, int highlight);
void print_info();
int choose();
void doMenu();

#endif
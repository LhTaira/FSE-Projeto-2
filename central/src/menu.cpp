#include <form.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;
int choice = 0;
WINDOW *menu_win;

char *choices[] = {
    "Ativar lampada 1",
    "Ativar lampada 2",
    "Ativar ar condicionado 1",
    "Ativar ar condicionado 2",
    "Sair",
};

int n_choices = sizeof(choices) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight) {
  int x, y, i;

  x = 2;
  y = 2;
  box(menu_win, 0, 0);
  for (i = 0; i < n_choices; ++i) {
    if (highlight == i + 1) /* High light the present choice */
    {
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, "%s", choices[i]);
      wattroff(menu_win, A_REVERSE);
    } else
      mvwprintw(menu_win, y, x, "%s", choices[i]);
    ++y;
  }
  wrefresh(menu_win);
}

int choose() {
  choice = 0;
  int highlight = 1;
  int c;
  startx = (80 - WIDTH) / 2;
  starty = (24 - HEIGHT) / 2;

  menu_win = newwin(HEIGHT, WIDTH, starty, startx);
  keypad(menu_win, TRUE);
  mvprintw(0, 0, "Use setas para navegar e Enter para selecionar uma opcao.");
  refresh();
  print_menu(menu_win, highlight);
  while (1) {
    c = wgetch(menu_win);
    switch (c) {
      case KEY_UP:
        if (highlight == 1)
          highlight = n_choices;
        else
          --highlight;
        break;
      case KEY_DOWN:
        if (highlight == n_choices)
          highlight = 1;
        else
          ++highlight;
        break;
      case 10:
        choice = highlight;
        break;
      default:
        mvprintw(
            24, 0,
            "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c,
            c);
        refresh();
        break;
    }
    print_menu(menu_win, highlight);
    if (choice != 0) /* User did a choice come out of the infinite loop */
      break;
  }
  return choice;
}

void doMenu() {
  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */

  do {
    choose();
    if (choice == 1) {
      //   screen2();
      clear();
    }
    if (choice == 2) {
      //   screenForm();
      clear();
    }

  } while (choice != 3);
  // pthread_kill(controllerThread, 9);
  refresh();
  clear();
  clrtoeol();
  endwin();
}

int main() {
  doMenu();
  while(1);
  return 0;
}
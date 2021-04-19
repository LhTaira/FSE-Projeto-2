#include "../inc/menu.hpp"

#include "../inc/global.hpp"

using namespace std;

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;
int choice = 0;
WINDOW *menu_win;
time_t timer, timer2;

string choices[] = {
    "Acionar lampada 1",
    "Acionar lampada 2",
    "Acionar lampada 3",
    "Acionar lampada 4",
    "Acionar ar condicionado 1",
    "Acionar ar condicionado 2",
    "Acionar alarme",
    "Sair",
};

int n_choices = sizeof(choices) / sizeof(string);

void print_menu(WINDOW *menu_win, int highlight) {
  int x, y, i;

  x = 2;
  y = 2;
  box(menu_win, 0, 0);
  for (i = 0; i < n_choices; ++i) {
    if (highlight == i + 1) /* High light the present choice */
    {
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
      wattroff(menu_win, A_REVERSE);
    } else
      mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
    ++y;
  }
  wrefresh(menu_win);
}

void print_info() {
  mvprintw(2, 0, "                                ");
  mvprintw(3, 0, "                                ");
  mvprintw(4, 0, "                                ");
  mvprintw(5, 0, "                                ");
  mvprintw(6, 0, "                                ");
  mvprintw(7, 0, "                                ");

  mvprintw(2, 20, "                                ");
  mvprintw(3, 20, "                                ");
  mvprintw(4, 20, "                                ");
  mvprintw(5, 20, "                                ");

  mvprintw(2, 45, "                                ");
  mvprintw(3, 45, "                                ");
  mvprintw(4, 45, "                                ");
  mvprintw(5, 45, "                                ");

  mvprintw(10, 0, "                 ");
  mvprintw(11, 0, "                 ");
  mvprintw(12, 0, "                 ");

  mvprintw(2, 0, "AC1: %s", arCondicionado[0].c_str());
  mvprintw(3, 0, "AC2: %s", arCondicionado[1].c_str());
  mvprintw(4, 0, "L1: %s", lampada[0].c_str());
  mvprintw(5, 0, "L2: %s", lampada[1].c_str());
  mvprintw(6, 0, "L3: %s", lampada[2].c_str());
  mvprintw(7, 0, "L4: %s", lampada[3].c_str());

  mvprintw(2, 20, "Presenca1: %s", presenca[0].c_str());
  mvprintw(3, 20, "Presenca2: %s", presenca[1].c_str());
  mvprintw(4, 20, "Abertura1: %s", abertura[0].c_str());
  mvprintw(5, 20, "Abertura2: %s", abertura[1].c_str());

  mvprintw(2, 45, "Abertura3: %s", abertura[2].c_str());
  mvprintw(3, 45, "Abertura4: %s", abertura[3].c_str());
  mvprintw(4, 45, "Abertura5: %s", abertura[4].c_str());
  mvprintw(5, 45, "Abertura6: %s", abertura[5].c_str());

  mvprintw(10, 0, "Alarme: %s", alarme.c_str());

  // time(&timer2);
  mvprintw(11, 0, "Umidade: %s", umidade.c_str());
  mvprintw(12, 0, "Temperatura: %s", temperatura.c_str());
  refresh();
}

int choose() {
  halfdelay(1);
  time(&timer);
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
    print_info();
    // mvprintw(12, 0, "asdaFAESF");
    refresh();
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
    if (choice != 0) break;
  }
  return choice;
}

void doMenu() {
  initscr();
  clear();
  noecho();
  cbreak();
  do {
    choose();
    switch (choice) {
      case 1:
        send_message(ip_distribuido, porta_distribuido, (string) "l1");
        log_event("aciona_lampada_1");
        break;
      case 2:
        send_message(ip_distribuido, porta_distribuido, (string) "l2");
        log_event("aciona_lampada_2");
        break;
      case 3:
        send_message(ip_distribuido, porta_distribuido, (string) "l3");
        log_event("aciona_lampada_3");
        break;
      case 4:
        send_message(ip_distribuido, porta_distribuido, (string) "l4");
        log_event("aciona_lampada_4");
        break;
      case 5:
        send_message(ip_distribuido, porta_distribuido, (string) "a1");
        log_event("aciona_ar_condicionado_1");
        break;
      case 6:
        send_message(ip_distribuido, porta_distribuido, (string) "a2");
        log_event("aciona_ar_condicionado_2");
        break;
      case 7:
        // send_message(ip_distribuido, porta_distribuido, (string) "a");
        if(string("Ligado").compare(alarme) == 0) {
          alarme = "Desligado";
        } else {
          alarme = "Ligado";
        }
        log_event("aciona_alarme");
        break;
      default:
        break;
    }

  } while (choice != 8);

  refresh();
  clear();
  clrtoeol();
  endwin();
}
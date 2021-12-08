#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "demineirb.h"
#include "print.h"
#include "ncurses.h"

void check_term_size(struct dimension dim)
{
    if (dim.cols < MIN_COLS || dim.rows < MIN_ROWS)
    {
        move(0, 0);
        printw("Veuillez agrandir la fenêtre du terminal (%d,%d) et relancer le programme.\n", MIN_COLS, MIN_ROWS);
        getch();
        endwin();
        exit(0);
    }
}

void draw_board(int nb_box_w, int nb_box_h)
{
    WINDOW *boite = NULL;

    for(int i = 0; i < nb_box_w; i++)
    {
        for(int j = 0; j < nb_box_h; j++)
        {
            boite = subwin(stdscr, H_BOX, W_BOX, MARGIN+H_BOX*i, MARGIN+W_BOX*j);
            box(boite, ACS_VLINE, ACS_HLINE);
            wrefresh(boite);
        }
    }
}

void print_welcome_message()
{
    mvprintw(20, 33, "Bienvenue dans le jeu Demin'eirb!");
    mvprintw(24, 35, "Pour quitter, appuyez sur 'q'.");
    mvprintw(25, 27, "Pour continuer, appuyez sur une autre touche.");
    mvprintw(45, 41, "Auteur Axel Nguyen.");
    mvprintw(47, 45, "Version 0.1");
    refresh();
    int c = getch();
    if(c == 'q')
    {
        endwin();
        exit(0);
    }
    for(int i = 0; i < 33; i++)
        mvdelch(20, 33);
    for(int i = 0; i < 30; i++)
        mvdelch(24, 35);
    for(int i = 0; i < 45; i++)
        mvdelch(25, 28);
    for(int i = 0; i < 21; i++)
        mvdelch(45, 41);
    for(int i = 0; i < 11; i++)
        mvdelch(47, 45);
}

void init_colors()
{
    start_color();

    init_pair(WHITE_BLACK,   COLOR_WHITE,   COLOR_BLACK);
    init_pair(MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);

    bkgd(COLOR_PAIR(WHITE_BLACK));
}

void color_selected_box(int pos_x, int pos_y, short color_pair)
{
    WINDOW *boite;
    boite = subwin(stdscr, H_BOX, W_BOX, MARGIN+H_BOX*pos_y, MARGIN+W_BOX*pos_x);
    wbkgd(boite, COLOR_PAIR(color_pair));
    box(boite, ACS_VLINE, ACS_HLINE);
    wrefresh(boite);
}

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

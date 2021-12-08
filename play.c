#include <stdlib.h>

#include "ncurses.h"
#include "play.h"
#include "print.h"

void init_keyboard()
{
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
}

void case_select(int ch, struct coordonnee *C_Matrice)
{

    color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, WHITE_BLACK);

    switch (ch)
    {
    case 'q':
        endwin();
        exit(0);
        break;

    break;

    case KEY_DOWN:
        if (C_Matrice->ordonnee < NB_BOX_H - 1)
            C_Matrice->ordonnee++;
        else
            C_Matrice->ordonnee = 0;
        break;

    case KEY_UP:
        if (C_Matrice->ordonnee > 0)
            C_Matrice->ordonnee--;
        else
            C_Matrice->ordonnee = NB_BOX_H-1;    
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, MAGENTA_BLACK);
        break;

    case KEY_RIGHT:
        if (C_Matrice->abscisse < NB_BOX_W - 1)
            C_Matrice->abscisse++;
        else
            C_Matrice->abscisse = 0;
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, MAGENTA_BLACK);
        break;

    case KEY_LEFT:
        if (C_Matrice->abscisse > 0)
            C_Matrice->abscisse--;
        else
            C_Matrice->abscisse = NB_BOX_W-1;
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, MAGENTA_BLACK);
        break;

    default:
        break;
    }

    color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, MAGENTA_BLACK);
}

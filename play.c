#include <stdlib.h>
#include <time.h>

#include "ncurses.h"
#include "play.h"
#include "print.h"

void init_keyboard()
{
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
}

void case_select(int ch, struct coordonnee *C_Matrice, int (*g_matrice)[NB_BOX_H], int (*p_matrice)[NB_BOX_H])
{

    if(g_matrice[C_Matrice->abscisse][C_Matrice->ordonnee] == UNKNOWN)
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, WHITE_BLACK);
    else if(g_matrice[C_Matrice->abscisse][C_Matrice->ordonnee] == MINE)
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, RED_BLACK);

    switch (ch)
    {
    case 'q':
        endwin();
        exit(0);
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
        break;

    case KEY_RIGHT:
        if (C_Matrice->abscisse < NB_BOX_W - 1)
            C_Matrice->abscisse++;
        else
            C_Matrice->abscisse = 0;
        break;

    case KEY_LEFT:
        if (C_Matrice->abscisse > 0)
            C_Matrice->abscisse--;
        else
            C_Matrice->abscisse = NB_BOX_W - 1;
        break;

    default:
        break;
    }

    color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, MAGENTA_BLACK);
}

void init_player_matrice(int (*player_matrice)[NB_BOX_H])
{
    for(int i = 0; i < NB_BOX_W; i++)
    {
        for(int j = 0; j < NB_BOX_H; j++)
        {
            player_matrice[i][j] = UNKNOWN;
        }
    }
}

void init_game_matrice(int (*game_matrice)[NB_BOX_H])
{
    srand(time(NULL));   // Initialisation pour la generation de nombres aleatoires

    for(int i = 0; i < NB_BOX_W; i++) // Initialisation de toutes les cases a UNKNOWN
    {
        for(int j = 0; j < NB_BOX_H; j++)
        {
            game_matrice[i][j] = UNKNOWN;
        }
    }

    for(int i = 0; i < NB_MINE; i++)
    {
        int r1, r2;
        while(1)
        {
            r1 = rand() % NB_BOX_W;
            r2 = rand() % NB_BOX_H;
            if(game_matrice[r1][r2] == UNKNOWN) // Generation aleatoire des coordonnees des NB_MINE 
            {
                game_matrice[r1][r2] = MINE;
                break;
            }
            else
                continue;
        }
    }
}
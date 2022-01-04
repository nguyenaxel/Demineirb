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

int case_select(int ch, struct coordonnee *C_Matrice, struct case_ (*g_matrice)[NB_BOX_H], struct case_ (*p_matrice)[NB_BOX_H])
{
    if(p_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type == UNKNOWN)
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, WHITE_BLACK);
    else if(p_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type == MINE)
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, RED_BLACK);
    else if(p_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type == KNOWN)
        color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, BLUE_BLACK);

    switch (ch)
    {
    case 'q':
        return 1;
        break;

    case ' ':
        if(g_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type == MINE)
        {
            print_mine(g_matrice);
            char c = getch();
            delete_board();
            print_end_message(LOSE);
            return 1;
        }
        else if(g_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type == KNOWN)
        {
            p_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type = KNOWN;
            mvprintw(C_Matrice->ordonnee*5+3, C_Matrice->abscisse*9+5, "%d", g_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].nb_mine_around);
            color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, BLUE_BLACK);
            return 0;
        }
        break;

    case 'm':
        if(g_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type != MINE)
        {
            print_mine(g_matrice);
            char c = getch();
            delete_board();
            print_end_message(LOSE);
            return 1;
        }
        else
        {
            mvprintw(C_Matrice->ordonnee*5+3, C_Matrice->abscisse*9+5, "M");
            color_selected_box(C_Matrice->abscisse, C_Matrice->ordonnee, RED_BLACK);
            mine_left--;
            for(int i = 0; i < 15; i++)
                mvdelch(52, 2);
            mvprintw(52, 2, "Mine left : %d", mine_left);
            p_matrice[C_Matrice->abscisse][C_Matrice->ordonnee].type = MINE;

            if(mine_left == 0)
            {
                delete_board();
                print_end_message(WIN);
                break;
            }
        }
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

    return 0;
}

void init_player_matrice(struct case_ (*player_matrice)[NB_BOX_H])
{
    for(int i = 0; i < NB_BOX_W; i++)
    {
        for(int j = 0; j < NB_BOX_H; j++)
        {
            player_matrice[i][j].type = UNKNOWN;
        }
    }
}

void init_game_matrice(struct case_ (*game_matrice)[NB_BOX_H])
{
    srand(time(NULL));   // Initialisation pour la generation de nombres aleatoires

    for(int i = 0; i < NB_BOX_W; i++) // Initialisation de toutes les cases a KNOWN
    {
        for(int j = 0; j < NB_BOX_H; j++)
        {
            game_matrice[i][j].type = KNOWN;
            game_matrice[i][j].nb_mine_around = 0;
        }
    }

    for(int i = 0; i < NB_MINE; i++)
    {
        int r1, r2;
        while(1)
        {
            r1 = rand() % NB_BOX_W;
            r2 = rand() % NB_BOX_H;
            if(game_matrice[r1][r2].type == KNOWN) // Generation aleatoire des coordonnees des NB_MINE 
            {
                if(r1 > 0)
                {
                    game_matrice[r1-1][r2].nb_mine_around++;

                    if(r2 > 0)
                        game_matrice[r1-1][r2-1].nb_mine_around++;

                    if(r2 < NB_BOX_H)
                        game_matrice[r1-1][r2+1].nb_mine_around++;
                }
                if(r1 < NB_BOX_W)
                {
                    game_matrice[r1+1][r2].nb_mine_around++;

                    if(r2 > 0)
                        game_matrice[r1+1][r2-1].nb_mine_around++;

                    if(r2 < NB_BOX_H-1)
                        game_matrice[r1+1][r2+1].nb_mine_around++;
                }
                if(r2 > 0)
                {
                    game_matrice[r1][r2-1].nb_mine_around++;
                    if(r2 < NB_BOX_H-1)
                        game_matrice[r1][r2+1].nb_mine_around++;
                }

                game_matrice[r1][r2].type = MINE;

                break;
            }
            else
                continue;
        }
    }
}
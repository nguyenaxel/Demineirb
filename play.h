#ifndef _PLAY_H
#define _PLAY_H

#include "demineirb.h"

enum case_type
{
    UNKNOWN,
    MINE
};

void init_keyboard();
void case_select(int ch, struct coordonnee *C_Matrice, int (*g_matrice)[NB_BOX_H], int (*p_matrice)[NB_BOX_H]);
void init_player_matrice(int (*player_matrice)[NB_BOX_H]);
void init_game_matrice(int (*game_matrice)[NB_BOX_H]);

#endif

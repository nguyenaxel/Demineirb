#ifndef _PLAY_H
#define _PLAY_H

#include "demineirb.h"

enum case_type
{
    UNKNOWN,
    KNOWN,
    MINE
};

enum end_type
{
    LOSE,
    WIN
};

void init_keyboard();
int  case_select(int ch, struct coordonnee *C_Matrice, struct case_ (*g_matrice)[NB_BOX_H], struct case_ (*p_matrice)[NB_BOX_H]);
void init_player_matrice(struct case_ (*player_matrice)[NB_BOX_H]);
void init_game_matrice(struct case_ (*game_matrice)[NB_BOX_H]);

#endif

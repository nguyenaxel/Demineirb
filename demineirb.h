#ifndef _DEMINEIRB_H
#define _DEMINEIRB_H

#define NB_BOX_H 10
#define NB_BOX_W 10

#define MIN_COLS 100
#define MIN_ROWS 55

#define NB_MINE  10

#define W_BOX  9
#define H_BOX  5
#define MARGIN 1

#define WHITE_BLACK     0
#define MAGENTA_BLACK   1
#define RED_BLACK       2
#define BLACK_BLACK     3
#define BLUE_BLACK      4

struct coordonnee
{
    int abscisse;
    int ordonnee;
};

struct case_
{
    int type;
    int nb_mine_around;
};

int mine_left;

#endif

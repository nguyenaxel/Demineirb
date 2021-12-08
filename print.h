#ifndef _PRINT_H
#define _PRINT_H

#include "demineirb.h"
#include "ncurses.h"

void check_term_size(struct dimension dim);
void draw_board(int nb_box_w, int nb_box_h);
void print_welcome_message();
void init_colors();
void color_selected_box(int pos_x, int pos_y, short color_pair);

#endif

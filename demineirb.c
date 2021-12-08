#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "demineirb.h"
#include "ncurses.h"
#include "print.h"

int main(int argc, char *argv[])
{
    // Initialisation de l'affichage
    struct dimension dim = initialize_screen();
    check_term_size(dim);
    curs_set(FALSE);
    init_colors();

    // Affichage du message de bienvenue
    print_welcome_message();

    // Affichage du plateau de jeu
    draw_board(NB_BOX_W, NB_BOX_H);
    color_selected_box(0, 0, MAGENTA_BLACK);

    // Attente interraction utilisateur
    char c = getch();

    // Fin de l'affichage ncurses
    release_screen();

    return 0;   
}

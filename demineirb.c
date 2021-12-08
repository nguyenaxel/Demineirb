#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "demineirb.h"
#include "ncurses.h"
#include "print.h"

int main(int argc, char *argv[])
{
    struct dimension dim = initialize_screen();
    check_term_size(dim);
    curs_set(FALSE);

    print_welcome_message();

    draw_board(NB_BOX_W, NB_BOX_H);

    char c = getch();

    release_screen();

    return 0;   
}

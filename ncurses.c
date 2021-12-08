#include "ncurses.h"

struct dimension initialize_screen()
{
    initscr(); // Start nCurses
    raw(); // Disable buffering (i.e. don't wait for CR)
    noecho(); // Don't show typed charected on screen
    keypad(stdscr, TRUE); // Allow F1, F2, F..., Arrows, etc ...

    struct dimension dim;
    getmaxyx(stdscr, dim.rows, dim.cols);
    return dim;
}

void release_screen()
{
    endwin(); // Release nCurses
}

void start_delayed_interaction(int delay)
{
    // halfdelay(delay);
    timeout(delay);
}

void stop_delayed_interaction()
{
    cbreak();
}

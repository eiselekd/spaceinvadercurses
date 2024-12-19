#include <chrono>
#include <thread>
#include <ncurses.h>

using namespace std::chrono_literals;

#include "g.h"

#define FPS_PERIOD (1000/60)

WINDOW *win = 0;

game::game() {
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    mvprintw(0, 0, "Press 'q' to quit");
    refresh();
    win = newwin(32, 64, 1, 0);
    wtimeout(win, FPS_PERIOD);
    box(win, 0, 0);
    wrefresh(win);
    refresh();

    //paint(10,10,'.');
}

void game::loop() {
    int r;
    while (true) {

	const auto start = std::chrono::high_resolution_clock::now();
	r = wgetch(win);
	const auto end = std::chrono::high_resolution_clock::now();
	auto waited = end - start;
	if (waited <= std::chrono::milliseconds(FPS_PERIOD)) {
	    std::this_thread::sleep_for(std::chrono::milliseconds(FPS_PERIOD) - waited);
	}

	int key = 0;
	if (r == 'q')
	    break;
	if (r != ERR) {
	    key = r;
	}
	wclear(win);
	box(win, 0, 0);

	tick(key);

	wrefresh(win);
	//refresh();

    }
    endwin();
}

void game::paint(int x, int y, char c) {
    char b[2] = { c, 0};
    mvwprintw(win, x, y, b);
}

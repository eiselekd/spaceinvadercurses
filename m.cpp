#include "g.h"
#include <ncurses.h>

class my_game : public game {
public:
    virtual void tick(int key) override {

	if (key) {
	}

	paint(x, 1,'|');
	c++;
	if (c > 60) {
	    c = 0;
	    x++;
	}
    };
    int x = 0;
    int c = 0;
};

int main(int argc, char **argv) {

    my_game g;
    g.loop();
    return 0;
}

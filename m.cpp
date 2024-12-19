#include "g.h"
#include "char_assets.h"
#include <ncurses.h>

int ship_position = 30;

class my_game : public game {
public:
    virtual void tick(int key) override {

		paint(28,ship_position, space_ship_top);
	    paint(29,ship_position, space_ship_bottom);

	if (key) {
		switch (key)
		{
		case 'a':
		    if (ship_position != 1) {
                ship_position--;
			}
			paint(28,ship_position, space_ship_top);
	        paint(29,ship_position, space_ship_bottom);
			break;
		case 'd':
		    if (ship_position+5 != 63) {
                ship_position++;
			}
			paint(28,ship_position, space_ship_top);
	        paint(29,ship_position, space_ship_bottom);
			break;
		
		case 'w':	    
			shoot(ship_position,'^');
			break;

		default:
			break;
		}

	} 
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

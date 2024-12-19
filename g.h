
int init_main(int argc, char **argv);

class game {
public:
    game();

    void loop();

    virtual void tick(int ) = 0;
    void paint(int x, int y, char * c);
    void paint_char(int x, int y , char c);
    void shoot(int x,char c);
};

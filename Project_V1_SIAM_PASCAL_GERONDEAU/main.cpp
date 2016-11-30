#include <iostream>
#include "main.hpp"
using namespace std;

int main()
{
    allegro_init();
    install_mouse();
    install_keyboard();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400, 600,0,0);
    Console*pEcran=NULL;
    pEcran = Console::getInstance();
    Game jeu(pEcran);
    jeu.test();
    //jeu.start();
    return 0;
} END_OF_MAIN();

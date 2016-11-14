#include <iostream>
#include "main.hpp"
using namespace std;

int main()
{
    allegro_init();
    al_install_mouse();
    al_install_keyboard();
    al_create_display(400,400);
    Game jeu();
    //jeu.start();
    return 0;
}

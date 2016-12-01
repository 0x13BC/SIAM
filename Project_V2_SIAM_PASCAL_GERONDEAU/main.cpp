#include <iostream>
#include "main.hpp"

#include <conio.h>
//#include <windows.h>
#include <iostream>

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

system ( "color 20" );

    int choice=0;
        do
        {
            cout<<"Enter your choice:"<<endl
                 <<"                    (1).Jouer."<<endl
                 <<"                    (2).Option."<<endl
                 <<"                    (0).Quit."<<endl
                 <<"Choice:";
            cin>>choice;

            switch(choice)
            {
            case 1:

                system("cls");

                jeu.test();
                //jeu.start();

            break;
            case 2:

            break;
            case 0:
                cout<<"Quit..."<<endl;
                break;
            default:
            system("cls");
            cout<<"Error...Wrong input!"<<endl;
            break;
            }

        }while(choice!=0);

    remove_mouse();
    remove_keyboard();
    allegro_exit();
    Console::deleteInstance();

    return 0;
} END_OF_MAIN();

#include <iostream>
#include "main.hpp"

using namespace std;

void getCursorXY(int &x, int&y) {

		CONSOLE_SCREEN_BUFFER_INFO csbi;

		if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
			x = csbi.dwCursorPosition.X;
			y = csbi.dwCursorPosition.Y;
		}
}

int main()
{
    allegro_init();
    install_mouse();
    install_keyboard();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400, 600,0,0);
    Console*pEcran=NULL;
    pEcran = Console::getInstance();
    Game jeu(pEcran);
    POINT lol;
    int x,y;

    system("color 20");

    int choice=0;
        do
        {
            cout<<"Enter your choice:"<<endl
                 <<"                    (1).Jouer."<<endl
                 <<"                    (2).Option."<<endl
                 <<"                    (3).Test curseur."<<endl
                 <<"                    (0).Quit."<<endl
                 <<"Choice:";
            cin>>choice;

            switch(choice)
            {
            case 1:

                system("cls");

                //jeu.test();
                jeu.start();

            break;
            case 3:
                GetCursorPos(&lol);
                pEcran->gotoLigCol(10,0);
                getCursorXY(x,y);
                std::cout<<lol.x<<" "<<lol.y<<std::endl;

                std::cout<<x<<" "<<y;
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
    system("color 20");

    return 0;
} END_OF_MAIN();

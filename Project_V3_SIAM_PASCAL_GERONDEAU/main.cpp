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

void options(Game& jeu, Console* ecran)
{
    char choix;
    if(jeu.GetdisplayMod())cout<< "Voulez-vous passer en mode graphique?" << endl;
    else cout<<"Voulez-vous quitter le mode graphique?" << endl;
    cout << "(1) Oui" << endl
    << "(2) Non" << endl;
    choix=ecran->getInputKey();
    if(choix=='1')jeu.SetdisplayMod((jeu.GetdisplayMod()? 0:1));
}
int main()
{
    allegro_init();
    install_mouse();
    install_keyboard();
    Console*pEcran=NULL;
    pEcran = Console::getInstance();
    Game jeu(pEcran);
    POINT lol;///CAN BE DESTROYED
    int x,y;

    //system("COLOR A");
    pEcran->setColor(COLOR_GREEN);
    jeu.homepage(20,5);

    int choice=0;
        do
        {
            cout<<"Enter your choice:"<<endl
                 <<"                    (1).Jouer."<<endl
                 <<"                    (2).Option."<<endl
                 <<"                    (0).Quit."<<endl
                 <<"Choice:";
            choice=pEcran->getInputKey();

            switch(choice)
            {
            case '1':

                system("cls");

                //jeu.test();
                jeu.start();
                jeu.reset();

            break;
            case '2':
                system("cls");
                options(jeu, pEcran);

                break;
            /*case '3':
                GetCursorPos(&lol);///CAN BE DESTROYED
                pEcran->gotoLigCol(10,0);
                getCursorXY(x,y);
                std::cout<<lol.x<<" "<<lol.y<<std::endl;///CAN BE DESTROYED

                std::cout<<x<<" "<<y;
            break;*/
            case '0':
                cout<<"Quit..."<<endl;
                break;
            default:
            system("cls");
            cout<<"Error...Wrong input!"<<endl;
            break;
            }

        }while(choice!='0');

    remove_mouse();
    remove_keyboard();
    //allegro_exit();
    Console::deleteInstance();
    system("color 20");

    return 0;
} END_OF_MAIN();

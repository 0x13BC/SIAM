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
    char choix=0;
    if(!jeu.GetdisplayMod())cout<< "Voulez-vous passer en mode graphique?" << endl;
    else cout<<"Voulez-vous quitter le mode graphique?" << endl;
    cout << "(1) Oui" << endl
    << "(2) Non" << endl;
    while(choix!='1' && choix!='2')
    {
        choix=ecran->getInputKey();
        if(choix=='1')jeu.SetdisplayMod((jeu.GetdisplayMod()? 0:1));
    }
}
int main()
{

    /*Graphic*pGraph=NULL;
    pGraph= Graphic::GetInstce();

    if(!pGraph)
    {
        cout<<"Cannot load allegro!";
        system("pause");
    }
    if(pGraph->init())
        {
        cout<<"Cannot load images!";
        system("pause");
    };*/

    Console*pEcran=NULL;
    pEcran = Console::getInstance();
    Game jeu(pEcran,NULL);

    //system("COLOR A");
    pEcran->setColor(COLOR_GREEN);

    jeu.homepage(20,5);
    pEcran->showCursor(false);

    int choice=0;
        do
        {
            for(int y=0; y<MARGINBOARDY; y++)
                {
                    std::cout<<std::endl;
                }
            for(int x=0; x<MARGINBOARDX; x++)cout<<" ";cout<<"\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB"<<endl;
           for(int x=0; x<MARGINBOARDX; x++)cout<<" "; cout<<"\xBA Enter your choice:            \xBA"<<endl;
            for(int x=0; x<MARGINBOARDX; x++)cout<<" "; cout<<"\xBA                   (1).Jouer.  \xBA"<<endl;
             for(int x=0; x<MARGINBOARDX; x++)cout<<" ";cout<<"\xBA                   (2).Option. \xBA"<<endl;
             for(int x=0; x<MARGINBOARDX; x++)cout<<" ";cout<<"\xBA                   (0).Quit.   \xBA"<<endl;
            for(int x=0; x<MARGINBOARDX; x++)cout<<" ";cout<<"\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC";
            choice=pEcran->getInputKey();

            switch(choice)
            {
            case '1':

                system("cls");

                //jeu.test();
                pEcran->showCursor(TRUE);
                jeu.start();
                jeu.reset();
                system("cls");

            break;
            case '2':
                system("cls");
                options(jeu, pEcran);

                break;
          /*  case '3':
                GetCursorPos(&lol);///CAN BE DESTROYED
                pEcran->gotoLigCol(10,0);
                getCursorXY(x,y);
                std::cout<<lol.x<<" "<<lol.y<<std::endl;///CAN BE DESTROYED

                std::cout<<x<<" "<<y;
            break;*/
            case '0':
                cout<<endl<<"Quit..."<<endl;
                break;
            default:
            system("cls");
            cout<<"Error...Wrong input!"<<endl;
            break;
            }

        }while(choice!='0');

    Console::deleteInstance();
    system("color 20");

    return 0;
} END_OF_MAIN();

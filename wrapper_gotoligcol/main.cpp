#include <iostream>
#include "console.h"

#define NTAILLE 5
#define MULTIPLICATOR 3


void homepage(int x0,int y0)
{

            for(int y=0;y<y0;y++){std::cout<<std::endl;}


            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"   \xDB\xDB\xDB\xDB\xDB   "<<"   \xDB\xDB\xDB\xDB\xDB\xDB  "<<"     \xDB\xDB  "<<"   \xDB       \xDB"<<std::endl;
             for(int x=0;x<x0;x++){std::cout<<" ";}std::cout<<"\xDB\xDB         "<<"      \xDB    "<<"    \xDB\xDB\xDB  "<<"  \xDB \xDB     \xDB \xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"\xDB          "<<"     \xDB\xDB   "<<"    \xDB \xDB\xDB  "<<" \xDB\xDB  \xDB\xDB  \xDB\xDB \xDB\xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"\xDB\xDB         "<<"     \xDB    "<<"   \xDB\xDB \xDB\xDB  "<<" \xDB\xDB   \xDB \xDB   \xDB\xDB"<<std::endl;
             for(int x=0;x<x0;x++){std::cout<<" ";}std::cout<<"   \xDB\xDB\xDB     "<<"     \xDB    "<<"   \xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"     \xDB\xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"      \xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB\xDB\xDB\xDB\xDB  "<<" \xDB\xDB    \xDB    \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"      \xDB\xDB    "<<"  \xDB\xDB     "<<" \xDB\xDB\xDB   \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"      \xDB     "<<"  \xDB      "<<" \xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"\xDB\xDB\xDB\xDB\xDB       "<<"\xDB\xDB\xDB\xDB\xDB    "<<"\xDB\xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl<<std::endl<<std::endl;
           for(int x=0;x<x0+8;x++){std::cout<<" ";} std::cout<<"PRESS ANY KEY TO CONTINUE:";


}

int main()
{
    bool quit = false;
    Console* pConsole = NULL;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(5, 10);
    pConsole->setColor(COLOR_GREEN);
    std::cout << "Hello World !" << std::endl;
    pConsole->gotoLigCol(5, 10);
    homepage(5,10);
    pConsole->setColor(COLOR_DEFAULT);
pConsole->showCursor(false);
    // Boucle événementielle
    while (!quit)
    {
        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // Récupère le code ASCII de la touche
            int key = pConsole->getInputKey();
            std::cout << "touche = " << key << std::endl;

            if (key == 'a' || key == 27) // 27 = touche escape
            {
                quit = true;
            }
        }
    }


    // Libère la mémoire du pointeur !
    Console::deleteInstance();

    return 0;
}



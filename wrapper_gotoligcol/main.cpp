#include <iostream>
#include "console.h"

#define NTAILLE 5
#define MULTIPLICATOR 3


void ShowOption(Console*ecran ,int x0,int y0)
{
        ecran->setColor(COLOR_GREEN);

        ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Z: Up               \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA S: Down             \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Q: Left             \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA D: Right            \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA                     \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Space:Switch order  \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Escape: Cancel      \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA 1 or 0 : choice     \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA                     \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC";





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
    ShowOption(pConsole,10,10);
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



#include <iostream>
#include "console.h"

#define NTAILLE 5
#define MULTIPLICATOR 3



int DamierCase(Console* pConsole)
{
    for(int i=0; i<NTAILLE*MULTIPLICATOR; i++)
    {
        pConsole->setColor(COLOR_DEFAULT);
        if(!(i%MULTIPLICATOR))
        {
            for(int k=0; k<NTAILLE*MULTIPLICATOR+NTAILLE; k++)std::cout<<"-";
            std::cout<<std::endl;
        }
        for(int j=0; j<=NTAILLE*MULTIPLICATOR; j++)
        {
            if(!(j%MULTIPLICATOR))std::cout<<"|";

            pConsole->setColor(COLOR_NDEFAULT);
            std::cout<<" ";
            pConsole->setColor(COLOR_DEFAULT);

        }


        std::cout<<std::endl;
    }

    return 0;
}

int DamierCaseV2(Console*pConsole)
{
    for(int i=0; i<NTAILLE*MULTIPLICATOR; i++)
    {
        pConsole->setColor(COLOR_BLUE);
        if(!(i%MULTIPLICATOR))
        {
            for(int k=0; k<NTAILLE*MULTIPLICATOR; k++)std::cout<<"--";
            for(int k=0; k<=NTAILLE; k++)std::cout<<"-";
            std::cout<<std::endl;
        }
        for(int j=0; j<NTAILLE*MULTIPLICATOR; j++)
        {
            if(!(j%MULTIPLICATOR))std::cout<<"|";

            pConsole->setColor(COLOR_NDEFAULT);
            if((i==MULTIPLICATOR/2+MULTIPLICATOR*(i/MULTIPLICATOR))
                    &&(j==(MULTIPLICATOR/2)+MULTIPLICATOR*(j/MULTIPLICATOR)))
            {
                std::cout<<"LL"; ///PUT BOARD[x][y] HERE!!!
                //pConsole->gotoLigCol(0,0);
                //std::cout<<NTAILLE/2;
                //pConsole->gotoLigCol(i*MULTIPLICATOR,j*MULTIPLICATOR);
            }
            else std::cout<<"  ";
            pConsole->setColor(COLOR_BLUE);

        }


        std::cout<<"|"<<std::endl;
    }
    for(int k=0; k<NTAILLE*MULTIPLICATOR; k++)std::cout<<"--";
    for(int k=0; k<=NTAILLE; k++)std::cout<<"-";
    std::cout<<std::endl;
    return 0;
}

int DamierGoto(Console* pConsole)
{
    (void)pConsole;
    return 0;
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
    pConsole->setColor(COLOR_DEFAULT);

   // DamierCaseV2(pConsole);
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



#include "BoardGame.hpp"
#include "General.h"

//----------------------------------------CTOR-&-DTOR----------------------------------------//

BoardGame::BoardGame()
{
    //ctor
}

BoardGame::~BoardGame()
{
    //dtor
}

//-------------------------------------SETTERS-&-GETTERS-------------------------------------//

Piece* BoardGame::Getmap(int x, int y)
{
    if(x<m_nTaille && x>=0 && y<m_nTaille && y>=0) return m_map[x][y];
    else return NULL;
}
void BoardGame::Addmap(Piece* val,int x, int y)
{
    if(x<m_nTaille && x>=0 && y<m_nTaille && y>=0) m_map[x][y] = val;
}
unsigned int BoardGame::GetnTaille()
{
    return m_nTaille;
}
void BoardGame::SetnTaille(unsigned int val)
{
    m_nTaille = val;
}
BITMAP* BoardGame::GetimgBoard()
{
    return m_imgBoard;
}
void BoardGame::SetimgBoard(BITMAP* val)
{
    m_imgBoard = val;
}

//------------------------------------------METHODS------------------------------------------//

void BoardGame::display(BITMAP* buffer, int disp_mod)
{
    (void)buffer;
    (void)disp_mod;
}

int BoardGame::boardCons(Console*pConsole)
{
    int test=0;
    int x=0,y=0;

    pConsole->gotoLigCol(MARGINBOARDY,MARGINBOARDX);
    for(int i=0; i<NTAILLE*MULTIPLICATOR; i++)
    {

        pConsole->setColor(COLOR_BLACK);
        if(!(i%MULTIPLICATOR))
        {
            pConsole->gotoLigCol(i+test+MARGINBOARDY,MARGINBOARDX);
            for(int k=0; k<NTAILLE*MULTIPLICATOR; k++)std::cout<<"--";
            for(int k=0; k<=NTAILLE; k++)std::cout<<"-";
            test++;
            //std::cout<<std::endl;
        }
        pConsole->gotoLigCol((i+test+MARGINBOARDY),MARGINBOARDX);
        for(int j=0; j<NTAILLE*MULTIPLICATOR; j++)
        {

            if(!(j%MULTIPLICATOR))std::cout<<"|";

            pConsole->setColor(COLOR_NDEFAULT);
            if((i==MULTIPLICATOR/2+MULTIPLICATOR*(i/MULTIPLICATOR))
                    &&(j==(MULTIPLICATOR/2)+MULTIPLICATOR*(j/MULTIPLICATOR)))
            {
                std::cout<<"LL"; ///PUT BOARD[x][y] HERE!!!
                x++;

            }
            else std::cout<<"  ";
            pConsole->setColor(COLOR_BLACK);

        }
        y++;
        std::cout<<"|"/*<<std::endl*/;
    }
    pConsole->gotoLigCol(MARGINBOARDY+test+NTAILLE*MULTIPLICATOR,MARGINBOARDX);
    for(int k=0; k<NTAILLE*MULTIPLICATOR; k++)std::cout<<"--";
    for(int k=0; k<=NTAILLE; k++)std::cout<<"-";
    std::cout<<std::endl;
    pConsole->setColor(COLOR_DEFAULT);
    return 0;
}

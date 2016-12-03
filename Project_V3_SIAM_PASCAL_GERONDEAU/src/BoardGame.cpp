#include "BoardGame.hpp"
#include "General.h"

//----------------------------------------CTOR-&-DTOR----------------------------------------//

BoardGame::BoardGame()
    :m_map(std::vector < std::vector<Piece*> >(5,std::vector<Piece*>(5,NULL)))
{
    for(int i=1;i<4;i++)
        m_map[i][2]= new Mountain(NULL);
    //ctor
    std::cout<<"ctor BoardGame();Map size: "<< m_map.size()<<std::endl;
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

void BoardGame::Setmap(int x, int y, Piece* pt)
{
    if(x>=0 && y>=0 && x<MAP_SIZEX && y<MAP_SIZEY) m_map[x][y]=pt;
}

//------------------------------------------METHODS------------------------------------------//

void BoardGame::display(BITMAP* buffer, int disp_mod,Console*pEcran)
{
    int posx=0,posy=0;

    (void)buffer;

    (void)disp_mod;

    pEcran->setColor(COLOR_NDEFAULT);

    for(int i=0;i<NTAILLE;i++)
    {
        for(int j=0; j<NTAILLE;j++)
        {
                posx=(2*(MULTIPLICATOR)*i)+i+MULTIPLICATOR+MARGINBOARDX;
                posy=(MULTIPLICATOR)*j+(j+1)+MULTIPLICATOR/2+MARGINBOARDY;
            pEcran->gotoLigCol(posy,posx);
            if(Getmap(i,j)!=NULL)
                std::cout<<Getmap(i,j)->Getstring(); ///PUT BOARD[x][y] HERE!!!
                else
                std::cout<<"  ";
        }
    }
    pEcran->setColor(COLOR_DEFAULT);
    pEcran->gotoLigCol(1+MARGINBOARDY+NTAILLE+NTAILLE*MULTIPLICATOR,MARGINBOARDX);
}


int BoardGame::boardCons(Console*pConsole)
{
    int shift=0;
    int x=0,y=0;

    pConsole->gotoLigCol(MARGINBOARDY,MARGINBOARDX);
    for(int i=0; i<NTAILLE*MULTIPLICATOR; i++)
    {

        pConsole->setColor(COLOR_BLUE);
        if(!(i%MULTIPLICATOR))
        {
            pConsole->gotoLigCol(i+shift+MARGINBOARDY,MARGINBOARDX);
            for(int k=0; k<NTAILLE*MULTIPLICATOR; k++)std::cout<<"\xC4\xC4";
            for(int k=0; k<=NTAILLE; k++)std::cout<<"\xC4";
            shift++;
            //std::cout<<std::endl;
        }
        pConsole->gotoLigCol((i+shift+MARGINBOARDY),MARGINBOARDX);
        for(int j=0; j<NTAILLE*MULTIPLICATOR; j++)
        {

            if(!(j%MULTIPLICATOR))std::cout<<"\xBA";

            pConsole->setColor(COLOR_NDEFAULT);
            std::cout<<"  ";
            pConsole->setColor(COLOR_BLUE);

        }
        x=0;
        if(i==(MULTIPLICATOR/2)+MULTIPLICATOR*(i/MULTIPLICATOR))
        y++;
        std::cout<<"\xBA"/*<<std::endl*/;
    }
    pConsole->gotoLigCol(MARGINBOARDY+shift+NTAILLE*MULTIPLICATOR,MARGINBOARDX);
    for(int k=0; k<NTAILLE*MULTIPLICATOR; k++)std::cout<<"\xC4\xC4";
    for(int k=0; k<=NTAILLE; k++)std::cout<<"\xC4";
    std::cout<<std::endl;
    pConsole->setColor(COLOR_DEFAULT);

    return 0;
}

int BoardGame::stockCons(Console*pConsole,int x0, int y0)
{
    int ysave=1;
    pConsole->gotoLigCol(y0,x0);
    std::cout<<"\xC4\xC4\xC4";

    for(int i=0;i<(NTAILLE*MULTIPLICATOR)+NTAILLE-1;i++)
    {
        pConsole->gotoLigCol(y0+ysave,x0);
        std::cout<<"\xB3"<<" "<<"\xB3";
        ysave++;
    }
    pConsole->gotoLigCol(y0+ysave,x0);
    std::cout<<"\xC4\xC4\xC4";

    return 0;
}


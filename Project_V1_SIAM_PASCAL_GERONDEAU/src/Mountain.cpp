#include "Mountain.hpp"
#define MAP_SIZEX 5
#define MAP_SIZEY 5
//----------------------------------------CTOR-&-DTOR----------------------------------------//

Mountain::Mountain(BITMAP* img)
: Piece(img)
{
    //ctor
}

Mountain::~Mountain()
{
    //dtor
}

//-------------------------------------SETTERS-&-GETTERS-------------------------------------//




//------------------------------------------METHODS------------------------------------------//


std::string Mountain::Getstring()
{
    return "MM";
}

void Mountain::display(BITMAP* dest, int disp_mod, Console* ecran)
{

}
int Mountain::push(BoardGame& board,char direction,char order, int power_sum)
{ ///FAUX A REFAIRE Cf RECURSIVITE PAWN.PUSH()
    int x=m_x, y=m_y;
    m_x+= (direction==1 || direction==-1 ? direction : 0);
    m_y+= (direction==2 || direction==-2 ? direction/ABS(direction) : 0);
    if(m_x<0 || m_y<0 || m_y>=MAP_SIZEY || m_x>=MAP_SIZEX) return true;
    else
    {
        board.Setmap(m_x,m_y, this);
        board.Setmap(x,y,NULL);
    }
}

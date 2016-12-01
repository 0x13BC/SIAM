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
    return "M ";
}

void Mountain::display(BITMAP* dest, int disp_mod, Console* ecran)
{

}
bool Mountain::push(BoardGame& board,char direction,char order)
{
    m_x+= (direction==1 || direction==-1 ? (m_x+direction<MAP_SIZEX && m_x+direction>=0 ? direction : 0): 0);
    m_y+= (direction==2 || direction==-2 ? (m_y+(direction/ABS(direction))<MAP_SIZEY && m_x+(direction/ABS(direction))>=0 ? direction : 0): 0);
}

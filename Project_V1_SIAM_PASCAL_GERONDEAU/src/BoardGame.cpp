#include "BoardGame.hpp"

BoardGame::BoardGame()
{
    //ctor
}

BoardGame::~BoardGame()
{
    //dtor
}

Piece* BoardGame::Getmap(int x, int y)
{
    if(x<m_nTaille && x>=0 && y<m_nTaille && y>=0) return m_map[x][y];
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

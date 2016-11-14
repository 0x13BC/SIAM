#include "BoardGame.hpp"

BoardGame::BoardGame()
{
    //ctor
}

BoardGame::~BoardGame()
{
    //dtor
}

Pawn *** Getmap()
{
    return m_map;
}
void Setmap(Pawn *** val)
{
    m_map = val;
}
unsigned int GetnTaille()
{
    return m_nTaille;
}
void SetnTaille(unsigned int val)
{
    m_nTaille = val;
}
BITMAP* GetimgBoard()
{
    return m_imgBoard;
}
void SetimgBoard(BITMAP* val)
{
    m_imgBoard = val;
}

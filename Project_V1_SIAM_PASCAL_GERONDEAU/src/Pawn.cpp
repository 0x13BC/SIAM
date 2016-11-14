#include "Pawn.hpp"

Pawn::Pawn()
{
    //ctor
}

Pawn::~Pawn()
{
    //dtor
}

/*Pawn::Pawn(const Pawn& other):Piece(const Piece & other)
{
    //copy ctor
}*/

char Pawn::GetOrientation()
{
    return m_Orientation;
}
void Pawn::SetOrientation(char val)
{
    m_Orientation = val;
}
unsigned short Pawn::Getteam()
{
    return m_team;
}
void Pawn::Setteam(unsigned short val)
{
    m_team = val;
}

#include "Piece.hpp"

Piece::Piece(BITMAP* image)
: m_imgPiece(image)
{

}

Piece::~Piece()
{
    //dtor
}

Piece::Piece(const Piece& other)
{
    //copy ctor
}


unsigned short Piece::Getx()
{
    return m_x;
}
void Piece::Setx(unsigned short val)
{
    m_x = val;
}
unsigned short Piece::Gety()
{
    return m_y;
}
void Piece::Sety(unsigned short val)
{
    m_y = val;
}
unsigned short Piece::Getstrength()
{
    return m_strength;
}
void Piece::Setstrength(unsigned short val)
{
    m_strength = val;
}
bool Piece::Getstate()
{
    return m_state;
}
void Piece::Setstate(bool val)
{
    m_state = val;
}
BITMAP* Piece::GetimgPiece()
{
    return m_imgPiece;
}
void Piece::SetimgPiece(BITMAP* val)
{
    m_imgPiece = val;
}

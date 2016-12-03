#include "Piece.hpp"

//----------------------------------------CTOR-&-DTOR----------------------------------------//

Piece::Piece(BITMAP* image, unsigned short team, float strength)
: m_imgPiece(image), m_strength(strength)
{
    m_state=FALSE;
    if(team<=2) m_team=team;
    else team=0;
}

Piece::~Piece()
{
    //dtor
}

Piece::Piece(const Piece& other)
{
    m_imgPiece= create_bitmap(other.m_imgPiece->w,other.m_imgPiece->h);
    blit(other.m_imgPiece,m_imgPiece, 0,0,0,0, m_imgPiece->w, m_imgPiece->h);
    m_strength=other.m_strength;
    m_state=other.m_state;
    m_x=other.m_x;
    m_team=other.m_team;
    m_y=other.m_y;
}

//-------------------------------------SETTERS-&-GETTERS-------------------------------------//

unsigned short Piece::Getx()
{
    return m_x;
}

unsigned short Piece::Gety()
{
    return m_y;
}
unsigned short Piece::Getstrength()
{
    return m_strength;
}

unsigned short Piece::Getteam()
{
    return m_team;
}
bool Piece::Getstate()
{
    return m_state;
}
void Piece::Setstate(bool val)
{
    m_state = val;
}
void Piece::Setx(int x)
{
    if(x<5 && x>=0) m_x=x;
}
void Piece::Sety(int y)
{
    if(y<5 && y>=0) m_y=y;
}
BITMAP* Piece::GetimgPiece()
{
    return m_imgPiece;
}
void Piece::SetimgPiece(BITMAP* val)
{
    m_imgPiece = val;
}

//------------------------------------------METHODS------------------------------------------//

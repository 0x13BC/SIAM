#include "Pawn.hpp"
#define RAPPORT 40
#define DECALAGE_X 20
#define DECALAGE_Y 20
#define PAWN_STRENGTH 1
Pawn::Pawn(BITMAP* img, unsigned short team)
: Piece(img, team, PAWN_STRENGTH), m_Orientation(1)
{
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


std::string Pawn::Getstring()
{
    std::string of_the_jedi="";
    of_the_jedi+= (m_team ? (m_team==1 ? "R" : "E") : "M");
    switch(m_Orientation)
    {
        case 1: of_the_jedi+= "d";
        break;
        case 2: of_the_jedi+= "b";
        break;
        case -1: of_the_jedi+= "g";
        break;
        case -2: of_the_jedi+= "h";
        break;
    }
    return of_the_jedi; //Because I can
}

void Pawn::display(BITMAP* dest, int disp_mode, Console* ecran)
{
    if(disp_mode)
    {
        rotate_sprite(dest, m_imgPiece, DECALAGE_X + m_x*RAPPORT,DECALAGE_Y + m_y*RAPPORT, (fixed)(m_Orientation*64));
    }

    (void)ecran;
}

bool Pawn::push(BoardGame& board,char direction,char order)
{
        (void)direction;
        (void)order;
}

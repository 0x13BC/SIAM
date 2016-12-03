#include "Pawn.hpp"
#include "Player.hpp"
#define RAPPORT 40
#define DECALAGE_X 20
#define DECALAGE_Y 20
#define MAP_SIZEX 5
#define MAP_SIZEY 5
#define PAWN_STRENGTH 1
Pawn::Pawn(BITMAP* img, unsigned short team, Player* wielder)
    : Piece(img, team, PAWN_STRENGTH), m_Orientation(1), m_wielder(wielder)
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
void Pawn::SetOrientation(int val)
{
    m_Orientation = val;
}


std::string Pawn::Getstring()
{
    std::string of_the_jedi="";
    of_the_jedi+= (m_team ? (m_team==1 ? "R" : "E") : "M");
    switch(m_Orientation)
    {
    case 1:
        of_the_jedi+= "d";
        break;
    case 2:
        of_the_jedi+= "b";
        break;
    case -1:
        of_the_jedi+= "g";
        break;
    case -2:
        of_the_jedi+= "h";
        break;
    }
    return of_the_jedi; //Because I can
}

void Pawn::display(BITMAP* dest)
{
        rotate_sprite(dest, m_imgPiece, DECALAGE_X + m_x*RAPPORT,DECALAGE_Y + m_y*RAPPORT, (fixed)(m_Orientation*64));
    }



int Pawn::push(BoardGame& board,char direction,char order, int power_sum, bool first)
{
    int add_x,add_y, bonus_strength, result;
    add_x= (direction==1 || direction==-1? direction : 0);
    add_y= (direction==2 || direction==-2? direction/ABS(direction) : 0);
    bonus_strength=m_strength*(direction==m_Orientation? 1 : (direction == -m_Orientation ? -1 : 0)); // Calcul de l(influence sur la poussée
    if(order==1)//move
    {
        if(power_sum+bonus_strength>0) //Si la pièce laisse la possibilité de pousser derrière
        {
            if(m_x+add_x>=0 && m_x+add_x<MAP_SIZEX && m_y+add_y<MAP_SIZEY && m_y+add_y>=0)
            {
                if(board.Getmap(m_x+add_x,m_y+add_y)==NULL) //EN ADMETTANT QU'ON INITIALISE TOUT LE TABLEAU + LES CASES IMMEDIATEMENT A L'EXTERIEUR A NULL
                {
                    board.Setmap(m_x,m_y,NULL);
                    board.Setmap(m_x+add_x,m_y+add_y,(Piece*)this);
                    m_x+=add_x;
                    m_y+=add_y;
                    return 1;

                }

                else
                {
                    if((result=board.Getmap(m_x+add_x,m_y+add_y)->push(board, direction, order, power_sum+bonus_strength, false))==1)//si la case d'après est d'accord
                    {
                        board.Setmap(m_x+add_x,m_y+add_y,(Piece*)this);
                        board.Setmap(m_x,m_y,NULL);
                        m_x+=add_x;
                        m_y+=add_y;
                        return 1;
                    }
                    else if(result==2)
                    {
                        if(bonus_strength>0)return m_team+2;
                        else return 2;
                    }
                    else  return -1;
                }
            }
            else
            {
                m_wielder->AddstockPiece(this);
                m_state=false;
                return 1;
            }
        }
        else if(board.Getmap(m_x+add_x,m_y+add_y)==NULL && first==true)
        {
            board.Setmap(m_x,m_y,NULL);


                    board.Setmap(m_x+add_x,m_y+add_y,(Piece*)this);
                    m_x+=add_x;
                    m_y+=add_y;
                    return 1;
        }
        else return -1;
    }
    else if(order==0)
    {
        switch(direction)
        {
        case 'z':
            m_Orientation=-2;
            break;
        case 'q':
            m_Orientation=-1;
            break;
        case 's':
            m_Orientation=2;
            break;
        case 'd':
            m_Orientation=1;
            break;
        }
    }
    return 0;
}


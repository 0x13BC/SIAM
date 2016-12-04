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

void Mountain::display(BITMAP* dest)
{
    (void)dest;
}
int Mountain::push(BoardGame& board,char direction,char order, float power_sum, bool first)
{
    int add_x,add_y, result;
    float bonus_strength;
    add_x= (direction==1 || direction==-1? direction : 0);
    add_y= (direction==2 || direction==-2? direction/ABS(direction) : 0);
    bonus_strength=-m_strength;// Calcul de l(influence sur la poussée
    if(power_sum+bonus_strength>0) //Si la pièce laisse la possibilité de pousser derrière
    {
        if(m_x+add_x>=0 && m_x+add_x<MAP_SIZEX && m_y+add_y<MAP_SIZEY && m_y+add_y>=0)
        {
            if(board.Getmap(m_x+add_x,m_y+add_y)==NULL) //EN ADMETTANT QU'ON INITIALISE TOUT LE TABLEAU + LES CASES IMMEDIATEMENT A L'EXTERIEUR A NULL
            {
                board.Setmap(m_x,m_y,NULL);
                board.Setmap(m_x+add_x,m_y+add_y,(Piece*)this);
                return 1;
            }
            else
            {
                if((result=board.Getmap(m_x+add_x,m_y+add_y)->push(board, direction, order, power_sum+bonus_strength,false))==1)//si la case d'après est d'accord
                {
                    board.Setmap(m_x,m_y,NULL);
                    board.Setmap(m_x+add_x,m_y+add_y,(Piece*)this);

                    return 1;
                }
                else if(result==2) return 2;
                else  return -1;
            }
        }
        else return 2;

    }
    else if(first && board.Getmap(m_x+add_x,m_y+add_y)==NULL)
        {
                board.Setmap(m_x,m_y,NULL);
                board.Setmap(m_x+add_x,m_y+add_y,(Piece*)this);
                m_x+=add_x;
                m_y+=add_y;
                return 1;
            }
    else return -1;

    return 0;
}

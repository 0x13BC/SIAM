#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"


class Pawn : virtual public Piece
{
    public:
        Pawn();
        ~Pawn();
        Pawn(const Pawn& other);
        char GetOrientation();
        void SetOrientation(char val) ;
        unsigned short Getteam();
        void Setteam(unsigned short val);
    protected:
    private:
        char m_Orientation;
        unsigned short m_team;
};

#endif // PAWN_HPP

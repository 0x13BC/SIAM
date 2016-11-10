#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"


class Pawn : virtual public Piece
{
    public:
        Pawn();
        ~Pawn();
        Pawn(const Pawn& other);
        char GetOrientation() { return m_Orientation; }
        void SetOrientation(char val) { m_Orientation = val; }
        unsigned short Getteam() { return m_team; }
        void Setteam(unsigned short val) { m_team = val; }
    protected:
    private:
        char m_Orientation;
        unsigned short m_team;
};

#endif // PAWN_HPP

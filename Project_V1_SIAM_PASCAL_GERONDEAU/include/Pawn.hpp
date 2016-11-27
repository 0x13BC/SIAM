#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn :  public Piece
{
    public:
        Pawn(BITMAP* image, int team);
        ~Pawn();
        Pawn(const Pawn& other);
        char GetOrientation();
        void SetOrientation(char val);
        unsigned short Getteam();
        void Setteam(unsigned short val);
        virtual void display(BITMAP* dest, int disp_mode, Console* ecran);
        virtual void push();
    protected:

    private:
        char m_Orientation;
        unsigned short m_team;
};

#endif // PAWN_HPP

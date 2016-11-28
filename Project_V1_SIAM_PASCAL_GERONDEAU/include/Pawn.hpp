#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn :  public Piece
{
    public:
        Pawn(BITMAP* image, unsigned short team);
        ~Pawn();
        Pawn(const Pawn& other);
        char GetOrientation();
        void SetOrientation(char val);
        void display(BITMAP* dest, int disp_mode, Console* ecran);
        void push();

    private:
        char m_Orientation;
};

#endif // PAWN_HPP

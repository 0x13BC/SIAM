#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn :  public Piece
{
    private:

        // ATTRIBUTES

        char m_Orientation;

    public:

        //CTOR & DTOR

        Pawn(BITMAP* image, unsigned short team);
        ~Pawn();
        Pawn(const Pawn& other);

        //SETTERS & GETTERS

        char GetOrientation();
        void SetOrientation(char val);

        //METHODS

        void display(BITMAP* dest, int disp_mode, Console* ecran);
        bool push(char direction,char order);


};

#endif // PAWN_HPP

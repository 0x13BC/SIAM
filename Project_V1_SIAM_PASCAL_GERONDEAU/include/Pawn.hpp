#ifndef PAWN_HPP
#define PAWN_HPP

#include "BoardGame.hpp"



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
        void SetOrientation(int val);

        //METHODS

        void display(BITMAP* dest, int disp_mode, Console* ecran);
        int push(BoardGame& board,char direction,char order, int power_sum);
        std::string Getstring();


};

#endif // PAWN_HPP

#ifndef PIECE_HPP
#define PIECE_HPP

#include "General.h"
#include "Console.h"

class BoardGame;

class Piece
{
    protected:

        // ATTRIBUTES

        BITMAP* m_imgPiece;
        unsigned short int m_team;
        unsigned short int m_x;
        unsigned short int m_y;
        unsigned short int m_strength;
        bool m_state;


    public:

        //CTOR & DTOR

        Piece(BITMAP* image, unsigned short team=0, int strength=0);
        virtual ~Piece();
        Piece(const Piece& other);

        //SETTERS & GETTERS

        unsigned short Getx() ;
        unsigned short Gety() ;
        unsigned short Getstrength() ;
        unsigned short Getteam();
        void Setstrength(unsigned short val) ;
        bool Getstate() ;
        void Setstate(bool val);
        BITMAP* GetimgPiece();
        void SetimgPiece(BITMAP* val);

        //METHODS
        virtual void SetOrientation(int orientation)=0;
        virtual std::string Getstring()=0;
        virtual void display(BITMAP* dest, int disp_mod, Console* ecran)=0;
        virtual int push(BoardGame& board,char direction,char order, int power_sum)=0;

};

#endif // PIECE_HPP

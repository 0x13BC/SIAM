#ifndef PIECE_HPP
#define PIECE_HPP
#include "General.h"
#include "Console.h"

class BoardGame;

class Piece
{
    public:
        Piece(BITMAP* image);
        virtual ~Piece();
        Piece(const Piece& other);
        unsigned short Getx() ;
        void Setx(unsigned short val);
        unsigned short Gety() ;
        void Sety(unsigned short val) ;
        unsigned short Getstrength() ;
        void Setstrength(unsigned short val) ;
        bool Getstate() ;
        void Setstate(bool val);
        BITMAP* GetimgPiece();
        void SetimgPiece(BITMAP* val);
        virtual void display(){};
        virtual void push(){};
    protected:
        unsigned short m_x;
        unsigned short m_y;
        unsigned short m_strength;
        bool m_state;
        BITMAP* m_imgPiece;
};

#endif // PIECE_HPP

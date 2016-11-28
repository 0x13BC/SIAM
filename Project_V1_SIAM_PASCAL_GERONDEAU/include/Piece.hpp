#ifndef PIECE_HPP
#define PIECE_HPP
#include "General.h"
#include "Console.h"

class BoardGame;

class Piece
{
    public:
        Piece(BITMAP* image, unsigned short team=0, int strength=0);
        virtual ~Piece();
        Piece(const Piece& other);
        unsigned short Getx() ;
        unsigned short Gety() ;
        unsigned short Getstrength() ;
        unsigned short Getteam();
        void Setstrength(unsigned short val) ;
        bool Getstate() ;
        void Setstate(bool val);
        BITMAP* GetimgPiece();
        void SetimgPiece(BITMAP* val);
        virtual void display(BITMAP* dest, int disp_mod, Console* ecran)=0;
        virtual void push()=0;
    protected:
        unsigned short m_team;
        unsigned short m_x;
        unsigned short m_y;
        unsigned short m_strength;
        bool m_state;
        BITMAP* m_imgPiece;
};

#endif // PIECE_HPP

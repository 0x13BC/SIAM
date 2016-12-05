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
        float m_strength;
        bool m_state;


    public:

        //CTOR & DTOR

        Piece(BITMAP* image, unsigned short team=0/*TEAM MOUNTAIN*/, float strength=0.9);
        virtual ~Piece();
        Piece(const Piece& other);

        //SETTERS & GETTERS

        unsigned short Getx() ;
        unsigned short Gety() ;
        unsigned short Getstrength() ;
        unsigned short Getteam();

        void Setx(int x);
        void Sety(int y);
        void Setstrength(unsigned short val) ;
        bool Getstate() ;
        void Setstate(bool val);
        BITMAP* GetimgPiece();
        void SetimgPiece(BITMAP* val);


        //METHODS
        virtual int GetOrientation()=0;
        virtual void SetOrientation(int orientation)=0;
        virtual std::string Getstring()=0;
        virtual void display(BITMAP* dest)=0;
        virtual int push(BoardGame& board,char direction,char order, float power_sum, bool first)=0;

};

#endif // PIECE_HPP

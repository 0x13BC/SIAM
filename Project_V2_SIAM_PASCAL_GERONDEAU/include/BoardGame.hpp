#ifndef BOARDGAME_HPP
#define BOARDGAME_HPP
#include "Piece.hpp"
#include <vector>

#define NTAILLE 5
#define MULTIPLICATOR 3
#define MARGINBOARDX 10
#define MARGINBOARDY 10
#define MAP_SIZEX 5
#define MAP_SIZEY 5


class BoardGame
{
    private:
        // ATTRIBUTES
        std::vector< std::vector<Piece*> > m_map;
        int m_nTaille;
        BITMAP* m_imgBoard;

    protected:

    public:

        //CTOR & DTOR

        BoardGame();
        ~BoardGame();

        //SETTERS & GETTERS

        Piece* Getmap(int x, int y);
        void Addmap( Piece* pion,int x, int y);
        unsigned int GetnTaille();
        void SetnTaille(unsigned int val);
        BITMAP* GetimgBoard();
        void SetimgBoard(BITMAP* val);
        void Setmap(int x, int y, Piece* pt);

        //METHODS

        void display(BITMAP* buffer, int disp_mod);
        int boardCons(Console*pConsole);
        int stockCons(Console*pConsole,int x0,int y0);


};

#endif // BOARDGAME_HPP

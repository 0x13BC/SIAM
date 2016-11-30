#ifndef BOARDGAME_HPP
#define BOARDGAME_HPP
#include "Piece.hpp"
#include <vector>

#define NTAILLE 5
#define MULTIPLICATOR 3
#define MARGINBOARDX 10
#define MARGINBOARDY 10

using namespace std ;

class BoardGame
{
    private:
        // ATTRIBUTES
        vector< vector<Piece*> > m_map;
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

        //METHODS

        void display(BITMAP* buffer, int disp_mod);
        int boardCons(Console*pConsole);


};

#endif // BOARDGAME_HPP

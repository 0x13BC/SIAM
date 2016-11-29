#ifndef BOARDGAME_HPP
#define BOARDGAME_HPP
#include "Piece.hpp"
#include <vector>
using namespace std ;

class BoardGame
{
    private:
        // ATTRIBUTES
        vector< vector<Piece*> > m_map;
        unsigned int m_nTaille;
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


};

#endif // BOARDGAME_HPP

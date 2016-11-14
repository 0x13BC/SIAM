#ifndef BOARDGAME_HPP
#define BOARDGAME_HPP
#include "Piece.hpp"
#include <vector>
using namespace std ;

class BoardGame
{
    public:
        BoardGame();
        ~BoardGame();
        Piece* Getmap(int x, int y);
        void Addmap( Piece* pion,int x, int y);
        unsigned int GetnTaille();
        void SetnTaille(unsigned int val);
        BITMAP* GetimgBoard();
        void SetimgBoard(BITMAP* val);
    protected:
    private:
        vector< vector<Piece*> > m_map;
        unsigned int m_nTaille;
        BITMAP* m_imgBoard;
};

#endif // BOARDGAME_HPP

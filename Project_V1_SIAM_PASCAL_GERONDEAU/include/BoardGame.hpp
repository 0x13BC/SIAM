#ifndef BOARDGAME_HPP
#define BOARDGAME_HPP

#include "Pawn.hpp"


class BoardGame
{
    public:
        BoardGame();
        ~BoardGame();
        Pawn *** Getmap() { return m_map; }
        void Setmap(Pawn *** val) { m_map = val; }
        unsigned int GetnTaille() { return m_nTaille; }
        void SetnTaille(unsigned int val) { m_nTaille = val; }
        BITMAP* GetimgBoard() { return m_imgBoard; }
        void SetimgBoard(BITMAP* val) { m_imgBoard = val; }
    protected:
    private:
        Pawn *** m_map;
        unsigned int m_nTaille;
        BITMAP* m_imgBoard;
};

#endif // BOARDGAME_HPP

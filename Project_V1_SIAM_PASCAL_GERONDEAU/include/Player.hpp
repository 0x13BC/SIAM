#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stack>
#include "Pawn.hpp"


class Player
{
    public:
        Player();
        ~Player();
        Player(const Player& other);
        unsigned int GetnbrOut() { return m_nbrOut; }
        void SetnbrOut(unsigned int val) { m_nbrOut = val; }
        std::stack <Pawn*> GetstockPiece() { return m_stockPiece; }
        void SetstockPiece(std::stack <Pawn*> val) { m_stockPiece = val; }
    protected:
    private:
        unsigned int m_nbrOut;
        std::stack <Pawn*> m_stockPiece;
};

#endif // PLAYER_HPP

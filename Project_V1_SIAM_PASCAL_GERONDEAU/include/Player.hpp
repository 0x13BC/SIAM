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
        unsigned int GetnbrOut() ;
        void SetnbrOut(unsigned int val) ;
        int GetstockPiece() ;
        void SetstockPiece(Pawn* val) ;
    protected:
    private:
        unsigned int m_nbrOut;
        std::stack <Pawn*> m_stockPiece;
};

#endif // PLAYER_HPP

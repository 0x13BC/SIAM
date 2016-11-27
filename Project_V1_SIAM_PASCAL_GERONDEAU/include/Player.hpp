#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stack>
#include "Pawn.hpp"


class Player
{
    public:
        Player(int type);
        ~Player();
        Player(const Player& other);
        unsigned int GetnbrOut() ;
        void SetnbrOut(unsigned int val) ;
        int GetstockPiece() ;
        void AddstockPiece(Pawn* val) ;
        int Play(unsigned int display_mode, BoardGame& board);
    protected:
    private:
        unsigned int m_nbrOut;
        std::stack <Pawn*> m_stockPiece;
};

#endif // PLAYER_HPP

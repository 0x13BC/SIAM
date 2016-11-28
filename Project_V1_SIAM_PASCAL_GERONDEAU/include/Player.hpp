#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stack>
#include <ctime>
#include "Pawn.hpp"
#include "BoardGame.hpp"



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
        int Play(unsigned int display_mode, BoardGame& board, Console* ecran);
    protected:
    private:
        int Play_console(BoardGame& board, Console* ecran);
        int Play_alleg(BoardGame& board);
        bool auth_check(int x, int y, BoardGame& board);
        unsigned int m_nbrOut;
        std::stack <Pawn*> m_stockPiece;
};

#endif // PLAYER_HPP

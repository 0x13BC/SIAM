#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "General.h"

#include "Pawn.hpp"
#include "BoardGame.hpp"

#define NULLVOID (void*)0 ///DELETE LATER



class Player
{
     private:

        // ATTRIBUTES

        unsigned int m_nbrOut;
        std::stack <Pawn*> m_stockPiece;
        void turnPiece(BoardGame& board, int x, int y, Console* ecran);

    protected:

    public:
        //CTOR & DTOR
        Player(int type);
        ~Player();
        Player(const Player& other);

        //SETTERS & GETTERS
        unsigned int GetnbrOut() ;
        void SetnbrOut(unsigned int val) ;
        int GetstockPiece() ;
        void AddstockPiece(Pawn* val) ;
        Pawn* GivePawn();

        //METHODS PUBLIC
        int Play(unsigned int display_mode, BoardGame& board, Console* ecran);
        void harvest(unsigned int dispMod, BoardGame& board);
        void put(unsigned int dispMod, BoardGame& board);
        void pushPiece(unsigned int dispMod, BoardGame& board);

        int Play_console(BoardGame& board, Console* ecran);
        int Play_alleg(BoardGame& board);
        bool auth_check(int x, int y, BoardGame& board);

};

#endif // PLAYER_HPP

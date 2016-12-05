#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "General.h"

#include "Pawn.hpp"
#include "BoardGame.hpp"
#include "Graphic.hpp"
#define NULLVOID (void*)0 ///DELETE LATER



class Player
{
     private:

        // ATTRIBUTES

        unsigned int m_team;
        std::stack <Pawn*> m_stockPiece;
        void turnPiece(Piece* pion, Console* ecran);

    protected:

    public:
        //CTOR & DTOR
        Player(int type);
        ~Player();
        Player(const Player& other);

        //SETTERS & GETTERS
        unsigned int Getteam() ;
        void Setteam(unsigned int val) ;
        int GetstockPiece() ;
        void AddstockPiece(Pawn* val) ;
        Pawn* GivePawn();

        //METHODS PUBLIC
        int Play(unsigned int display_mode, BoardGame& board, Console* ecran, Graphic* Pgraph);
        void harvest(unsigned int dispMod, BoardGame& board);
        void put(unsigned int dispMod, BoardGame& board);
        void pushPiece(unsigned int dispMod, BoardGame& board);
        fixed get_angle(int orientation);
        void display_piece(Piece* piece, Graphic* Pgraph);
        int get_action(Piece* piece, Graphic* Pgraph);
        int get_rotate(Piece* piece, Graphic* Pgraph);
        int screen_to_board_x(int x);
        int screen_to_board_y(int y);
        int board_to_screen_x(int x);
        int board_to_screen_y(int y);
        int Play_console(BoardGame& board, Console* ecran);
        int Play_alleg(BoardGame& board, Graphic* Pgraph);
        bool auth_check(int x, int y, BoardGame& board);


};

#endif // PLAYER_HPP

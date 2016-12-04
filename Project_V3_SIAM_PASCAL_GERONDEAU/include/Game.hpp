#ifndef GAME_HPP
#define GAME_HPP

#include "BoardGame.hpp"
#include "Console.h"
#include "Player.hpp"


class Game
{
    private:
        // ATTRIBUTES

        Console* m_ecran;
        unsigned int m_displayMod;
        BoardGame m_BG;
        BITMAP* m_board_image;


     protected:

    public:
        //CTOR & DTOR

        Game(Console* ecran);
        ~Game();

        //SETTERS & GETTERS

        unsigned int GetdisplayMod() ;
        void SetdisplayMod(unsigned int val) ;

        //METHODS
        void win_display(int winner);
        void homepage(int x0, int y0);
        void start();
        void reset();
        void test();




};

#endif // GAME_HPP

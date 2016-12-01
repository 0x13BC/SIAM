#ifndef GAME_HPP
#define GAME_HPP

#include "BoardGame.hpp"
#include "Console.h"
#include "Player.hpp"


class Game
{
    private:
        // ATTRIBUTES

        unsigned int m_displayMod;
        BoardGame m_BG;
        BITMAP* m_board_image;
        Console* m_ecran;

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
        void start();
        void test();




};

#endif // GAME_HPP

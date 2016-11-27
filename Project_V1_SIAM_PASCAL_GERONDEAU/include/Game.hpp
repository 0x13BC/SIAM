#ifndef GAME_HPP
#define GAME_HPP

#include "BoardGame.hpp"
#include "Console.h"
#include "Player.hpp"


class Game
{
    public:
        Game(Console* ecran);
        ~Game();
        unsigned int GetdisplayMod() ;
        void SetdisplayMod(unsigned int val) ;
        void win_display(int winner);
        void Play();

    protected:
    private:
        unsigned int m_displayMod;
        BoardGame m_BG;
        BITMAP* m_board_image;
        Console* m_ecran;

};

#endif // GAME_HPP

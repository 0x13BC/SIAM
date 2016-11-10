#ifndef GAME_HPP
#define GAME_HPP

#include "BoardGame.hpp"


class Game
{
    public:
        Game();
        ~Game();
        unsigned int GetdisplayMod() { return m_displayMod; }
        void SetdisplayMod(unsigned int val) { m_displayMod = val; }
    protected:
    private:
        unsigned int m_displayMod;
        BoardGame m_BG;

};

#endif // GAME_HPP

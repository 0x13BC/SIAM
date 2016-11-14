#include "Game.hpp"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

unsigned int Game::GetdisplayMod()
{
    return m_displayMod;
}
void Game::SetdisplayMod(unsigned int val)
{
    m_displayMod = val;
}

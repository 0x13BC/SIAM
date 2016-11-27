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


void Game::Play()
{
    BITMAP* buffer=NULL;
    Joueur rhino();
    Joueur elephant();

    BoardGame board();

    int win=0;

    while(!win)
    {
        if(rhino.play(GetdisplayMod() ,&board)) win=1;
        else if(elephant.play(GetdisplayMod() ,&board)) win=2;
        board.display(buffer, GetdisplayMod());
        if(GetdisplayMod()) blit(buffer,source,0,0,0,0, SCREEN_W, SCREEN_H);
    }


}

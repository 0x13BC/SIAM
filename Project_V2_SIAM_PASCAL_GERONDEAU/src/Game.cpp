#include "Game.hpp"

//----------------------------------------CTOR-&-DTOR----------------------------------------//

Game::Game(Console* ecran)
: m_ecran(ecran)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

//-------------------------------------SETTERS-&-GETTERS-------------------------------------//

unsigned int Game::GetdisplayMod()
{
    return m_displayMod;
}
void Game::SetdisplayMod(unsigned int val)
{
    m_displayMod = val;
}

//------------------------------------------METHODS------------------------------------------//

void Game::win_display(int winner)
{
    if(GetdisplayMod())
    {

    }
    else
    {
        m_ecran->setColor(COLOR_GREEN);
        // m_ecran->gotoligcol(milieu_x-taille_msg/2, milieu_y);
        std::cout<< (winner==1 ? "Les rhinoceros": "Les elephants") << " gagnent !" << std::endl;
    }
}
void Game::start()
{
     BITMAP* buffer=NULL;

    Player rhino(1);
    Player elephant(2);


    int win=0;

    while(!win)
    {
        if(rhino.Play(GetdisplayMod() ,m_BG, m_ecran)) win=1;
        else if(elephant.Play(GetdisplayMod() ,m_BG, m_ecran)) win=2;
        m_BG.display(buffer, GetdisplayMod());
        if(GetdisplayMod()) blit(buffer,screen,0,0,0,0, SCREEN_W, SCREEN_H);
    }
    return win_display(win);

}

void Game::test()
{
    Pawn chocolate(NULL,1);
    m_BG.Setmap(1,2,&chocolate);
    m_BG.stockCons(m_ecran,10,6);
    m_BG.stockCons(m_ecran,10,46);
    m_BG.boardCons(m_ecran);
}

#include "Game.hpp"

//----------------------------------------CTOR-&-DTOR----------------------------------------//

Game::Game(Console* ecran)
: m_ecran(ecran),m_displayMod(0)
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
        std::cout<< (winner==3 ? "Les rhinoceros": "Les elephants") << " gagnent !" << std::endl;
    }
}
void Game::start()
{
     BITMAP* buffer=NULL;

    Player rhino(1);
    Player elephant(2);


    m_BG.boardCons(m_ecran);
    m_BG.stockCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY);
    m_BG.stockCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY);
    m_BG.display(NULL,0,m_ecran);




    int win=0;

    while(!win)
    {
        win=elephant.Play(GetdisplayMod() ,m_BG, m_ecran);

        if(win==3 || win==4) return win_display(win);
        else win=rhino.Play(GetdisplayMod() ,m_BG, m_ecran);

        if(win==3 || win==4) return win_display(win);
        m_BG.display(buffer, GetdisplayMod(),m_ecran);
        if(GetdisplayMod()) blit(buffer,screen,0,0,0,0, SCREEN_W, SCREEN_H);
    }


}

void Game::test()
{
    Pawn chocolate(NULL,1,NULL);
    Pawn chocolate2(NULL,0,NULL);
    Pawn chocolate3(NULL,0,NULL);
    Pawn chocolate4(NULL,1,NULL);

    Mountain vanilla(NULL);
    m_BG.Setmap(3,0,&chocolate);
    m_BG.Setmap(4,1,&chocolate2);
    m_BG.Setmap(2,3,&chocolate3);
    m_BG.Setmap(3,4,&vanilla);

    m_BG.stockCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY);
    m_BG.stockCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY);
    m_BG.boardCons(m_ecran);
    m_BG.display(NULL,0,m_ecran);

}

void Game::homepage(int x0,int y0)
{

            for(int y=0;y<y0;y++){std::cout<<std::endl;}


            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"   \xDB\xDB\xDB\xDB\xDB   "<<"   \xDB\xDB\xDB\xDB\xDB\xDB  "<<"     \xDB\xDB  "<<"   \xDB       \xDB"<<std::endl;
             for(int x=0;x<x0;x++){std::cout<<" ";}std::cout<<"\xDB\xDB         "<<"      \xDB    "<<"    \xDB\xDB\xDB  "<<"  \xDB \xDB     \xDB \xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"\xDB          "<<"     \xDB\xDB   "<<"    \xDB \xDB\xDB  "<<" \xDB\xDB  \xDB\xDB  \xDB\xDB \xDB\xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"\xDB\xDB         "<<"     \xDB    "<<"   \xDB\xDB \xDB\xDB  "<<" \xDB\xDB   \xDB \xDB   \xDB\xDB"<<std::endl;
             for(int x=0;x<x0;x++){std::cout<<" ";}std::cout<<"   \xDB\xDB\xDB     "<<"     \xDB    "<<"   \xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"     \xDB\xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
            for(int x=0;x<x0;x++){std::cout<<" ";} std::cout<<"      \xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB\xDB\xDB\xDB\xDB  "<<" \xDB\xDB    \xDB    \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"      \xDB\xDB    "<<"  \xDB\xDB     "<<" \xDB\xDB\xDB   \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"      \xDB     "<<"  \xDB      "<<" \xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
           for(int x=0;x<x0;x++){std::cout<<" ";}  std::cout<<"\xDB\xDB\xDB\xDB\xDB       "<<"\xDB\xDB\xDB\xDB\xDB    "<<"\xDB\xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl<<std::endl<<std::endl;
           for(int x=0;x<x0+8;x++){std::cout<<" ";} std::cout<<"PRESS ANY KEY TO CONTINUE:";
   m_ecran->showCursor(false);
   while(!m_ecran->isKeyboardPressed());
    m_ecran->getInputKey();
    m_ecran->showCursor(true);
    system("cls");

}

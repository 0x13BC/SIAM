#include "Game.hpp"

//----------------------------------------CTOR-&-DTOR----------------------------------------//

Game::Game(Console* ecran,Graphic* graph)
    : m_ecran(ecran),m_Graphic(graph),m_displayMod(0)
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
    if(GetdisplayMod())
    {
        m_Graphic=Graphic::GetInstce();
        m_Graphic->init();
        blit(m_Graphic->GetBoard(),m_Graphic->Getbuff(),0,0,BOARD_X_BLIT,BOARD_Y_BLIT,m_Graphic->GetBoard()->w,m_Graphic->GetBoard()->h);
    }
    Player rhino(RHINOCEROS);
    Player elephant(ELEPHANT);
    if(!GetdisplayMod())
    {
        ShowOption(m_ecran ,MARGINBOARDX+NTAILLE*MULTIPLICATOR+NTAILLE*3,MARGINBOARDY);
        m_BG.boardCons(m_ecran);
        m_BG.stockCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY);
        m_BG.stockCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY);
        m_BG.stockDispCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY,RHINOCEROS,rhino.GetstockPiece());
        m_BG.stockDispCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY,ELEPHANT,elephant.GetstockPiece());
        m_BG.display(NULL,0,m_ecran);
    }
    else m_BG.alleg_display( m_Graphic, &rhino);
    int win=0;

    while(!win) //BOUCLE DE JEU
    {
        win=elephant.Play(GetdisplayMod(),m_BG, m_ecran, m_Graphic);
        if(!GetdisplayMod()) m_BG.stockDispCons(m_ecran,MARGINBOARDX-3,MARGINBOARDY,ELEPHANT,elephant.GetstockPiece());
        else
        {
            m_BG.alleg_display( m_Graphic, &elephant);
            blit(m_Graphic->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
        }
        if(win==3 || win==4) return win_display(win);
        else
        {
            win=rhino.Play(GetdisplayMod(),m_BG, m_ecran, m_Graphic);
            if(!GetdisplayMod()) m_BG.stockDispCons(m_ecran,MARGINBOARDX+2*NTAILLE*MULTIPLICATOR+NTAILLE+1,MARGINBOARDY,RHINOCEROS,rhino.GetstockPiece());
            else
            {
                m_BG.alleg_display( m_Graphic, &rhino);
                blit(m_Graphic->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
            }
        }
        if(win==3 || win==4) return win_display(win);

        if(GetdisplayMod()) blit(m_Graphic->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
        else m_BG.display(NULL, GetdisplayMod(),m_ecran);
    }

if(GetdisplayMod()) m_Graphic->deleteInstce();
}

void Game::reset()
{
    for(int y=0; y<NTAILLE; y++)
    {
        for(int x=0; x<NTAILLE; x++)
        {
            if(m_BG.Getmap(x,y))
                m_BG.Setmap(x,y,NULL);



        }
    }
    for(int i=1; i<4; i++)
    {
        m_BG.Setmap(i,2,new Mountain(NULL));
    }
}


void Game::test()
{
    std::cout<<"GAME TEST";
    if(m_Graphic->GetRhn())std::cout<<"LE rhnino existe bordel!";

    blit(m_Graphic->GetRhn(),screen,0,0,100,100,m_Graphic->GetRhn()->w,m_Graphic->GetRhn()->h);
    textout_ex(screen, font, "TEST", 0, 50, COLOR_BLANC,-1);

}

void Game::homepage(int x0,int y0)
{

    for(int y=0; y<y0; y++)
    {
        std::cout<<std::endl;
    }


    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"   \xDB\xDB\xDB\xDB\xDB   "<<"   \xDB\xDB\xDB\xDB\xDB\xDB  "<<"     \xDB\xDB  "<<"   \xDB       \xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"\xDB\xDB         "<<"      \xDB    "<<"    \xDB\xDB\xDB  "<<"  \xDB \xDB     \xDB \xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"\xDB          "<<"     \xDB\xDB   "<<"    \xDB \xDB\xDB  "<<" \xDB\xDB  \xDB\xDB  \xDB\xDB \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"\xDB\xDB         "<<"     \xDB    "<<"   \xDB\xDB \xDB\xDB  "<<" \xDB\xDB   \xDB \xDB   \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"   \xDB\xDB\xDB     "<<"     \xDB    "<<"   \xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"     \xDB\xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB  \xDB\xDB  "<<" \xDB\xDB    \xDB\xDB   \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"      \xDB\xDB    "<<"   \xDB     "<<"  \xDB\xDB\xDB\xDB\xDB\xDB  "<<" \xDB\xDB    \xDB    \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"      \xDB\xDB    "<<"  \xDB\xDB     "<<" \xDB\xDB\xDB   \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"      \xDB     "<<"  \xDB      "<<" \xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl;
    for(int x=0; x<x0; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"\xDB\xDB\xDB\xDB\xDB       "<<"\xDB\xDB\xDB\xDB\xDB    "<<"\xDB\xDB     \xDB  "<<"\xDB\xDB         \xDB\xDB"<<std::endl<<std::endl<<std::endl;
    for(int x=0; x<x0+8; x++)
    {
        std::cout<<" ";
    }
    std::cout<<"PRESS ANY KEY TO CONTINUE:";
    m_ecran->showCursor(false);
    while(!m_ecran->isKeyboardPressed());
    m_ecran->getInputKey();
    m_ecran->showCursor(true);
    system("cls");

}
void Game::ShowOption(Console*ecran ,int x0,int y0)
{
        ecran->setColor(COLOR_GREEN);

        ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Z: Up               \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA S: Down             \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Q: Left             \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA D: Right            \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA                     \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Space:Switch order  \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA Escape: Cancel      \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA 1 or 0 : choice     \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xBA                     \xBA";ecran->gotoLigCol(y0,x0);y0++;
        std::cout<< "\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC";





}

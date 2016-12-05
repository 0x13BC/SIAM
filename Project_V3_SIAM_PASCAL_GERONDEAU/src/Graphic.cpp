#include "Graphic.hpp"

Graphic* Graphic::m_instance = NULL;

Graphic::Graphic()
:m_buffer(NULL),m_SprtBoard(NULL),m_SprtEleph(NULL),m_SprtRhino(NULL),m_SprtMount(NULL), m_Select(NULL)
{
    //ctor
}

Graphic::~Graphic()
{
    destroy_bitmap(m_up);
    destroy_bitmap(m_down);
    destroy_bitmap(m_left);
    destroy_bitmap(m_right);
    destroy_bitmap(m_Select);
    destroy_bitmap(m_SprtBoard);
    destroy_bitmap(m_SprtEleph);
    destroy_bitmap(m_SprtMount);
    destroy_bitmap(m_SprtRhino);
    uninit();
    //dtor
}


void Graphic::deleteInstce()
{
    clear(screen);
    set_gfx_mode(GFX_TEXT,0,0,0,0);

    delete m_instance;
    m_instance = NULL;
}

Graphic* Graphic::GetInstce()
{
    if (!Graphic::m_instance)
    {
        m_instance = new Graphic();
    }

    return m_instance;
}


int Graphic::init()
{


set_color_depth(32);
set_uformat(U_ASCII); // pour gérer les accents
allegro_init();

    if (install_mouse() == -1)
    {
        std::cout << ("Failed to install mouse") << std::endl;
        return 0;
    }
    if (install_keyboard() != 0)
    {
        std::cout << ("Failed to install keyboard") << std::endl;
        return 0;
    }
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, RESOLUTION_X, RESOLUTION_Y, 0, 0) != 0)
    {
        std::cout << ("Failed to enter in graphic mode") << std::endl;
        return false;
    }
    m_buffer=create_bitmap(RESOLUTION_X, RESOLUTION_Y);

    set_keyboard_rate(500, 100);


    return LoadAllSprites();
    }

int Graphic::LoadAllSprites()
{
    m_SprtBoard = LoadSprite("ressources/BOARDGAME.bmp");
    m_SprtEleph = LoadSprite("ressources/ELEPHANT.bmp");
    m_SprtMount = LoadSprite("ressources/MOUNTAIN.bmp");
    m_SprtRhino = LoadSprite("ressources/RHINOCEROS.bmp");
    m_Select    = LoadSprite("ressources/selec.bmp");
    m_up        = LoadSprite("ressources/up.bmp");
    m_left      = LoadSprite("ressources/left.bmp");
    m_down      = LoadSprite("ressources/down.bmp");
    m_right     = LoadSprite("ressources/right.bmp");
    m_turn      = LoadSprite("ressources/turn.bmp");
    if(!m_SprtBoard || !m_SprtEleph || !m_SprtMount|| !m_SprtRhino || !m_Select || !m_up || !m_left || !m_down || !m_right || !m_turn)return -1;
    else return 0;

}

BITMAP* Graphic::LoadSprite(std::string filepath)
{
    return load_bitmap(filepath.c_str(),NULL);
}


void Graphic::uninit()
{
    destroy_bitmap(m_buffer);
    remove_mouse();
    remove_keyboard();
    allegro_exit();
}


BITMAP* Graphic::Getbuff()
{
    return m_buffer;
}
BITMAP* Graphic::GetEle()
{
    return m_SprtEleph;
}
BITMAP* Graphic::GetMnt()
{
    return m_SprtMount;
}
BITMAP* Graphic::GetRhn()
{
    return m_SprtRhino;
}

BITMAP* Graphic::GetBoard()
{
    return m_SprtBoard;
}

BITMAP* Graphic::GetSel()
{
    return m_Select;
}
BITMAP* Graphic::GetUp()
{
    return m_up;
}
BITMAP* Graphic::GetLeft()
{
    return m_left;
}
BITMAP* Graphic::GetDown()
{
    return m_down;
}
BITMAP* Graphic::GetRight()
{
    return m_right;
}
BITMAP* Graphic::GetTurn()
{
    return m_turn;
}


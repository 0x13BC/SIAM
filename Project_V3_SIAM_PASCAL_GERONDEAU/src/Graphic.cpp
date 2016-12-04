#include "Graphic.hpp"

Graphic* Graphic::m_instance = NULL;

Graphic::Graphic()
        :m_buffer(NULL),m_SprtBoard(NULL),m_SprtEleph(NULL),m_SprtRhino(NULL),m_SprtMount(NULL)
{
    //ctor
}

Graphic::~Graphic()
{
    remove_mouse();
    remove_keyboard();
    //dtor
}


void Graphic::deleteInstce()
{
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

    set_keyboard_rate(500, 100);

    show_mouse(screen);

    return LoadAllSprites();}

int Graphic::LoadAllSprites()
{
    m_SprtBoard = LoadSprite("BOARDGAME.bmp");
    m_SprtEleph = LoadSprite("ELEPHANT.bmp");
    m_SprtMount = LoadSprite("MOUNTAIN.bmp");
    m_SprtRhino = LoadSprite("RHINOCEROS.bmp");

    if(m_SprtBoard ||m_SprtEleph||m_SprtMount||m_SprtRhino)return -1;
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


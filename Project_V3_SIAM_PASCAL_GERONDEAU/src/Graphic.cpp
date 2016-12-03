#include "Graphic.hpp"

Graphic::Graphic()
{
    //ctor
}

Graphic::~Graphic()
{
    remove_mouse();
    remove_keyboard();
    //dtor
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
   m_SprtBoard = LoadSprite("../ressources/BOARDGAME.bmp");
    m_SprtEleph = LoadSprite("../ressources/ELEPHANT.bmp");
    m_SprtMount = LoadSprite("../ressources/MOUNTAIN.bmp");
    m_SprtRhino = LoadSprite("../ressources/RHINOCEROS.bmp");

    if(!m_SprtBoard ||!m_SprtEleph||!m_SprtMount||!m_SprtRhino)return -1;
    else return 0;

}

BITMAP* Graphic::LoadSprite(std::string filepath)
{
    return load_bitmap(filepath.c_str(),NULL);
}



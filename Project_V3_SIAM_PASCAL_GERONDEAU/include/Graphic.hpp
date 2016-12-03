#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP
#include "General.h"




class Graphic
{
    public:
        Graphic();
        ~Graphic();

        int init();
        void deinit();

        void cursor(int l, int c, int color);


        BITMAP*GetMnt();
        BITMAP*GetRhn();
        BITMAP*GetEle();

        BITMAP*Getbuff();
        void Setbuff();

        int LoadAllSprites();
        BITMAP* LoadSprite(std::string filepath);


    private:
        BITMAP *m_SprtRhino,*m_SprtEleph,*m_SprtBoard,*m_SprtMount,*m_buffer;


};

#endif // GRAPHIC_HPP

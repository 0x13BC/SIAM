#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP
#include "General.h"




class Graphic
{
    public:

        // CTOR , DTOR , INIT UNINIT
        Graphic();
        ~Graphic();

         static Graphic* GetInstce();
         static void deleteInstce();

        int init();
        void uninit();

    //SETTER & GETTER

        BITMAP* GetMnt();
        BITMAP* GetRhn();
        BITMAP* GetEle();
        BITMAP* GetBoard();
        BITMAP* GetSel();
        BITMAP* GetUp();
        BITMAP* GetLeft();
        BITMAP* GetDown();
        BITMAP* GetRight();
        BITMAP* GetTurn();
        BITMAP* GetBackground();

        BITMAP* Getbuff();
        void Setbuff();

        int LoadAllSprites();
        BITMAP* LoadSprite(std::string filepath);


    private:
        static Graphic* m_instance;
        BITMAP *m_buffer, *m_SprtBoard, *m_SprtEleph,*m_SprtRhino, *m_SprtMount, *m_Select;
        BITMAP *m_up,*m_left,*m_down, *m_right, *m_turn, *m_background;


};

#endif // GRAPHIC_HPP

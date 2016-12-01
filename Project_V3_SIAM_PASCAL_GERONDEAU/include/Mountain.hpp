#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "BoardGame.hpp"


class Mountain : virtual public Piece
{

    private:

    protected:

    public:

        //CTOR & DTOR

        Mountain(BITMAP* img);
        ~Mountain();

        //SETTERS & GETTERS

        //METHODS
        std::string Getstring();
        void display(BITMAP* dest, int disp_mod, Console* ecran);
        int push(BoardGame& board,char direction,char order, int power_sum);
        void SetOrientation(int x){} //Unused virtual function



};

#endif // MOUNTAIN_HPP

#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "Piece.hpp"


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
        bool push(BoardGame& board,char direction,char order);



};

#endif // MOUNTAIN_HPP

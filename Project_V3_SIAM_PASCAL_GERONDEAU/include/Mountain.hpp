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
        void display(BITMAP* dest);
        int push(BoardGame& board,char direction,char order, float power_sum, bool first);
        void SetOrientation(int x){} //Unused virtual function



};

#endif // MOUNTAIN_HPP

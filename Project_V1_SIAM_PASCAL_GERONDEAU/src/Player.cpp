#include "Player.hpp"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    //copy ctor
}s
unsigned int GetnbrOut()
{
    return m_nbrOut;
}
void SetnbrOut(unsigned int val)
{
    m_nbrOut = val;
}
int GetstockPiece()
{
    return m_stockPiece.size();
}
void AddstockPiece(Pawn* val)
{
    m_stockPiece.push(val);
}

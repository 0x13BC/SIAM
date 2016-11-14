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
}
unsigned int Player::GetnbrOut()
{
    return m_nbrOut;
}
void Player::SetnbrOut(unsigned int val)
{
    m_nbrOut = val;
}
int Player::GetstockPiece()
{
    return m_stockPiece.size();
}
void Player::AddstockPiece(Pawn* val)
{
    m_stockPiece.push(val);
}

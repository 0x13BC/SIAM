#include "Player.hpp"
#define NB_PIONS_PLAYER 5
Player::Player(int type)
{
    for(unsigned int i=0; i<NB_PIONS_PLAYER;i++) m_stockPiece.push(new Pawn(create_bitmap(10,10), type));
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

int Player::Play(unsigned int diplay_mode, BoardGame& board)
{

}

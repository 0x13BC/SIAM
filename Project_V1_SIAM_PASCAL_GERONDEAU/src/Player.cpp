#include "Player.hpp"
#define NB_PIONS_PLAYER 5
#define DECALAGE_X_TEXT 10
#define DECALAGE_Y_TEXT 3
#define BOARD_HEIGHT 5
#define BOARD_WIDTH  5
#define MARGIN 2
using namespace std;


//----------------------------------------CTOR-&-DTOR----------------------------------------//


Player::Player(int type)
{
    for(unsigned int i=0; i<NB_PIONS_PLAYER; i++) m_stockPiece.push(new Pawn(create_bitmap(10,10), type));
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    //copy ctor
    (void)other;
}

//-------------------------------------SETTERS-&-GETTERS-------------------------------------//


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

Pawn* Player::GivePawn()
{
    return m_stockPiece.top();
}

//------------------------------------------METHODS------------------------------------------//

bool Player::auth_check(int x, int y, BoardGame& board)
{
    if(board.Getmap(x,y)!= NULL)
    {
        if(board.Getmap(x,y)->Getteam()==m_stockPiece.top()->Getteam()) return TRUE;
        else return FALSE;
    }
    return FALSE;
}

void Player::harvest(unsigned int dispMod, BoardGame& board)

{
    //AddstockPiece(board.Getmap(0,0));
    (void)dispMod;
    (void)board;

}

void Player::put(unsigned int dispMod, BoardGame& board)

{
    int x=0;
    int y=0;
    if(board.Getmap(x,y)== NULLVOID)
    {
        board.Addmap(GivePawn(),x,y);
    }
    (void)dispMod;
}

void Player::pushPiece(unsigned int dispMod, BoardGame& board)

{
    (void)dispMod;
    (void)board;
}

void Player::turnPiece(BoardGame& board, int x, int y, Console* ecran)
{
    char touche=' ';
    ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
    cout<<"Dans quelle direction tourne la piece?";
    while(touche!='z' && touche!='q' && touche!='s' && touche!='d')
    {
        touche=ecran->getInputKey();
        switch(touche)
        {
        case 'z':
            board.Getmap(x,y)->SetOrientation(-2);
            break;
        case 'q':
            board.Getmap(x,y)->SetOrientation(-1);
            break;
        case 's':
            board.Getmap(x,y)->SetOrientation(2);
            break;
        case 'd':
            board.Getmap(x,y)->SetOrientation(1);
            break;
        }
    }
}

int Player::Play_console(BoardGame& board, Console* ecran)
{
    char touche;
    int test=-1, test2=0;
    int x=0, y=0;
    char order=1;
    char direction='d';
    int select=0;
    ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);

    if(GetstockPiece()==NB_PIONS_PLAYER) test=0;
    else
    {
        cout<< "Que souhaitez vous faire?" << endl;
        cout<< "0: faites entrer une piece" << endl;
        cout<< "1: choisissez une piece" << endl;
        while(test!=0 && test!=1)
        {
            test=ecran->getInputKey();
            if(test!=0 && test!=1)
            {
                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN+3);
                cout<<"Saisie invalide, recommencez";
            }
        }
        //clear weiting zone
        ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
        cout<<"                                                  "<<endl;
        cout<<"                                                  "<<endl;
        cout<<"                                                  "<<endl;
        cout<<"                                                  "<<endl;
        if(test)
        {
            time_t t=time(NULL);
            while(test)
            {
                ecran->gotoLigCol(DECALAGE_X_TEXT+5*x, DECALAGE_Y_TEXT+y);
                if(test2)
                {
                    if(board.Getmap(x,y)!=NULL) board.Getmap(x,y)->display(NULL,0,ecran);
                    else cout << "OO";
                }
                else cout<< "  ";
                if(ecran->isKeyboardPressed())
                {
                    touche=ecran->getInputKey();
                    switch(touche)
                    {
                    case '\r':
                        if(!select && auth_check(x,y, board)) select=1;
                        else if(board.Getmap(x,y)->push(board, direction, order,0)!=-1)
                        {
                            test=0; /// CANNOT PUT BOARD IN PIECE CAUSE CALL LOOP
                        }
                        else
                        {
                            ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            cout<<"                                  "<<endl;
                            cout<<"                                  "<<endl;
                            ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            cout<<"Mouvement impossible, selectionnez une autre action";
                            time_t timer=time(NULL);
                            while(difftime(time(NULL), timer)<2);
                            ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            cout<<"                                                                           "<<endl;
                            select=0;
                        }
                        break;
                    case 27: //escape
                        if(!select) return -1;
                        else select=0;
                    case 'z':
                        if(y>0 && !select) y--;
                        break;
                    case 'q':
                        if(x>0 && !select) x--;
                        break;
                    case 's':
                        if (y<BOARD_HEIGHT && !select) y++;
                        break;
                    case 'd':
                        if(x<BOARD_WIDTH && !select) x++;
                        break;
                    case ' ':
                        if(select) order = (order ?  0 : 1);
                        break;
                    }
                    if (select) direction=touche;
                    ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                    cout<< (char)(y+'A'-1) << x;
                    if(select)
                    {
                        ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN+1);
                        cout<< "Ordre: " << (order ? "move" : "turn only");
                        switch(direction)
                        {
                        case 'z':
                            cout << " up";
                            break;
                        case 'q':
                            cout << " left";
                            break;
                        case 's':
                            cout << " down";
                            break;
                        case 'd':
                            cout << " right";
                            break;
                        }

                    }
                    if(difftime(time(NULL),t)-(int)difftime(time(NULL),t) <= 0.1) test2= (test2 ? 0 : 1);
                }

            }
        }
    }
    return 0;
}

int Player::Play(unsigned int display_mode, BoardGame& board, Console* ecran)
{
    if(!display_mode) return(Play_console(board, ecran));
    else return(Play_alleg(board));

}

int Player::Play_alleg(BoardGame& board)
{
    (void)board;
    return 0;
}

#include "Player.hpp"
#define NB_PIONS_PLAYER 5
#define DECALAGE_X_TEXT 10
#define DECALAGE_Y_TEXT 10
#define BOARD_HEIGHT 5
#define BOARD_WIDTH  5
#define MARGIN 2
using namespace std;


//----------------------------------------CTOR-&-DTOR----------------------------------------//


Player::Player(int type)
{
    for(unsigned int i=0; i<NB_PIONS_PLAYER; i++) m_stockPiece.push(new Pawn(create_bitmap(10,10), type, this));
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
    //cout<<m_stockPiece.size();
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
        board.Setmap(x,y,GivePawn());
    }
    (void)dispMod;
}

void Player::pushPiece(unsigned int dispMod, BoardGame& board)

{
    (void)dispMod;
    (void)board;
}

void Player::turnPiece(Piece* pion, Console* ecran)
{
    char touche=' ';
    while(touche!='z' && touche!='q' && touche!='s' && touche!='d')
    {
        touche=ecran->getInputKey();
        switch(touche)
        {
        case 'z':
            pion->SetOrientation(-2);
            break;
        case 'q':
            pion->SetOrientation(-1);
            break;
        case 's':
            pion->SetOrientation(2);
            break;
        case 'd':
            pion->SetOrientation(1);
            break;
        }
    }
}


int Player::Play_console(BoardGame& board, Console* ecran)
{
    char touche;
    int win_test=0;
    int boucle=1;
    int test=-1, test2=0;
    int x=0, y=0;
    char order=1;
    char direction='d';
    int select=0;
    ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
//-----------------------------------WHILE BOUCLE, BOUCLE GENERALE DE JEU DU JOUER ==> DROIT DE RETRACTTIOn DE DECISION-------------
    while(boucle)
    {
        ecran->setColor(COLOR_NDEFAULT);
        if(GetstockPiece()==NB_PIONS_PLAYER) test=0;
        else
        {
            cout<< "Que souhaitez vous faire?" << endl;
            cout<< "0: faites entrer une piece" << endl;
            cout<< "1: choisissez une piece" << endl;
            while(test!='0' && test!='1')
            {
                test=ecran->getInputKey();
                if(test!='0' && test!='1')
                {
                    ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN+3);
                    cout<<"Saisie invalide, recommencez";
                }
                if(test==27) return -1; ///OU CALL PAUSE ==> PAUSE DANS GAME OU PAS?
            }
            //clear weiting zone

            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
            cout<<"                                                  "<<endl;
            cout<<"                                                  "<<endl;
            cout<<"                                                  "<<endl;
            cout<<"                                                  "<<endl;
        }
        if(test)
        {
            time_t t=time(NULL);
//----------------------------------------------------WHILE TEST BOUCLE DE SELECTION DE CASE--------------------------------------------
            ecran->showCursor(false);
            while(test)
            {
                ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                if(test2)
                {
                    ecran->setColor(COLOR_WHITEANDBLACK);
                    if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                    else cout <<"  ";

                }
                else
                {
                    ecran->setColor(COLOR_NDEFAULT);
                    if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                    else cout <<"  ";
                }
                if(ecran->isKeyboardPressed())
                {
                    touche=ecran->getInputKey();
                    switch(touche)
                    {
                    case '\r':
                        if(!select)
                        {
                            if(auth_check(x,y, board)) select=1;
                            else
                            {
                                ecran->setColor(COLOR_NDEFAULT);
                                ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                cout<<"                                  "<<endl;
                                cout<<"choix non valide"<<endl;
                            }
                        }
                        else if((win_test=board.Getmap(x,y)->push(board, direction, order,0, true))!=-1)
                        {
                            board.boardCons(ecran);
                            board.display(NULL,0,ecran);
                            test=0;
                            boucle=0;
                        }
                        else
                        {
                            ecran->setColor(COLOR_NDEFAULT);
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
                        if(!select)
                        {
                            test=0; //EXIT BOUCLE SELECTION CASE, RETOUR CHOIX DE L'ACTION
                        }
                        else select=0;
                    case 'z':ecran->setColor(COLOR_NDEFAULT);

                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(y>0 && !select) y--;
                        test2=1;
                        break;
                    case 'q':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x>0 && !select) x--;
                        test2=1;
                        break;
                    case 's':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if (y+1<BOARD_HEIGHT && !select) y++;
                        test2=1;

                        break;

                    case 'd':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x+1<BOARD_WIDTH && !select) x++;
                        test2=1;
                        break;

                    case ' ':
                        if(select) order = (order ?  0 : 1);
                        break;
                    }
                    if (select) direction=(touche != ' ' && touche!= 27 && touche != '\r' ? touche : direction);
                    ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                    cout<< (char)(y+'A') << x;
                    if(select)
                    {
                        ecran->setColor(COLOR_NDEFAULT);

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
                    if(difftime(time(NULL),t) >= 0.2)
                    {
                        test2= (test2 ? 0 : 1);
                        t=time(NULL);
                    }
                }

            }
            ecran->showCursor(true);
        }
        else
        {
            time_t t=time(NULL);
            ecran->showCursor(false);
            while(!test)
            {
                ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                if(test2)
                {
                    ecran->setColor(COLOR_WHITEANDBLACK);
                    if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                    else cout <<"  ";
                }
                else
                {
                    ecran->setColor(COLOR_NDEFAULT);
                    if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                    else cout <<"  ";
                }
                if(difftime(time(NULL),t) >= 0.2)
                {
                    test2= (test2 ? 0 : 1);
                    t=time(NULL);
                }

                if(ecran->isKeyboardPressed())
                {
                    test2=1;
                    touche=ecran->getInputKey();

                    switch(touche)
                    {
                    case '\r':
                        if(!board.Getmap(x,y))
                        {
                            board.Setmap(x,y, m_stockPiece.top());
                            m_stockPiece.top()->Setstate(true);
                            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            cout<<"                                      ";
                            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            cout<<"Quelle est la direction de la pièce?";
                            turnPiece(m_stockPiece.top(),ecran);
                            m_stockPiece.pop();
                            ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                            test=1;
                            boucle=0;
                        }
                        else
                        {

                            if(x!=0 && x!=BOARD_WIDTH-1) m_stockPiece.top()->SetOrientation(y? -2: 2);
                            else if(y!=0 && y!=BOARD_HEIGHT-1) m_stockPiece.top()->SetOrientation(x? -1: 1);
                            else
                            {
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                cout<<"                                      ";
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                cout<<"Quelle est la direction de la pièce?";
                                turnPiece(m_stockPiece.top(),ecran);

                            }
                            if((win_test=board.Getmap(x,y)->push(board, m_stockPiece.top()->GetOrientation(), 1, m_stockPiece.top()->Getstrength(), false))!=-1)
                            {
                                board.Setmap(x,y, m_stockPiece.top());
                                m_stockPiece.top()->Setstate(true);
                                m_stockPiece.pop();
                                board.boardCons(ecran);
                            board.display(NULL,0,ecran);
                                test=1;
                                boucle=0;
                            }
                            else
                            {
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                cout<<"                                      ";
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                cout<<"Mouvement impossible!";
                            }
                        }


                        break;
                    case 27: //escape
                        if(!select)
                        {
                            test=1;
                        }
                        else select=0;
                        break;

                    case 'z':

                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(y>0 && (x==0 || x==BOARD_WIDTH-1) && !select) y--;
                        break;

                    case 'q':

                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x>0 && (y==0 || y==BOARD_HEIGHT-1) && !select) x--;
                        break;

                    case 's':

                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if (y+1<BOARD_HEIGHT && (x==0 || x==BOARD_WIDTH-1) && !select) y++;
                        break;

                    case 'd':

                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) cout<<board.Getmap(x,y)->Getstring();
                        else cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x+1<BOARD_WIDTH &&(y==0 || y==BOARD_HEIGHT-1) && !select) x++;
                        break;
                        ecran->setColor(COLOR_WHITEANDBLACK);
                    }
                }


                ///FAIRE RENTRER UNE PIECE
            }
            ecran->showCursor(TRUE);
        }
    }

    return (win_test==1 || win_test==2 ? 0 : win_test); //SI win_test==1 ou 2 le win n'est pas apparu, c'est juste que le mouvement s'est fait, il faut qu'il vaille 3 ou 4 pour que ça soit significatif
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

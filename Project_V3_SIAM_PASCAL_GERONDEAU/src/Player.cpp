#include "Player.hpp"
#define NB_PIONS_PLAYER 5
#define DECALAGE_X_TEXT 10
#define DECALAGE_Y_TEXT 10

#define MARGIN 2


//----------------------------------------CTOR-&-DTOR----------------------------------------//


Player::Player(int type)
    :m_team(type)
{
    for(unsigned int i=0; i<NB_PIONS_PLAYER; i++) m_stockPiece.push(new Pawn(NULL, type, this));
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


unsigned int Player::Getteam()
{
    return m_team;
}
void Player::Setteam(unsigned int val)
{
    m_team = val;
}
int Player::GetstockPiece()
{
    //std::cout<<m_stockPiece.size();
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
        if(board.Getmap(x,y)->Getteam()==m_team) return TRUE;
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
    while(touche!='z' && touche!='q' && touche!='s' && touche!='d'
            &&touche!='Z' && touche!='Q' && touche!='S' && touche!='D')
    {
        touche=ecran->getInputKey();
        switch(touche)
        {
        case 'z':
        case 'Z':
            pion->SetOrientation(-2);
            break;
        case 'q':
        case 'Q':
            pion->SetOrientation(-1);
            break;
        case 's':
        case 'S':
            pion->SetOrientation(2);
            break;
        case 'd':
        case 'D':
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
    char direction=1;
    char direction_save=1;
    Piece* buff=NULL;
    int select=0;
    int order_save=order;
    time_t t;
    ecran->showCursor(false);
//-----------------------------------WHILE BOUCLE, BOUCLE GENERALE DE JEU DU JOUER ==> DROIT DE RETRACTTIOn DE DECISION-------------
    while(boucle)
    {
        x=0;
        y=0;
        ecran->setColor(COLOR_GREEN);
        ecran->gotoLigCol(0,0);
        std::cout<<"              ";
        ecran->gotoLigCol(0,0);
        std::cout<< (m_team==RHINOCEROS ? "Tour RHINO" : "TOUR ELEPHANT");
        if(GetstockPiece()==NB_PIONS_PLAYER ) test=0;
        else
        {
            if(!GetstockPiece())test='1';
            else
            {
                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                std::cout<< "Que souhaitez vous faire?" << std::endl;

                std::cout<< "0: faites entrer une piece" << std::endl;
                std::cout<< "1: choisissez une piece" <<std::endl;
                while(test!='0' && test!='1')
                {
                    test=ecran->getInputKey();
                    if(test!='0' && test!='1' && test!=27)
                    {
                        ecran->gotoLigCol(3, 0);
                        std::cout<<"Saisie invalide, recommencez";
                        t=time(NULL);
                        while(difftime(time(NULL),t)<=0.5);
                        ecran->gotoLigCol(3, 0);
                        std::cout<<"                             "<<std::endl;

                    }
                    if(test==27) return -1;
                }

                ///OU CALL PAUSE ==> PAUSE DANS GAME OU PAS?
            }
            //clear weiting zone

            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
            std::cout<<"                                                  "<<std::endl;
            std::cout<<"                                                  "<<std::endl;
            std::cout<<"                                                  "<<std::endl;
            std::cout<<"                                                  "<<std::endl;
        }
        if(test=='1')
        {
            time_t t=time(NULL);
//----------------------------------------------------WHILE TEST BOUCLE DE SELECTION DE CASE--------------------------------------------

            while(test)
            {

                ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                if(test2)
                {
                    ecran->setColor(COLOR_WHITEANDBLACK);
                    if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                    else std::cout <<"  ";
                    ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                    std::cout<<"                                  "<<std::endl;

                }
                else
                {
                    ecran->setColor(COLOR_NDEFAULT);
                    if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                    else std::cout <<"  ";
                }

                if(test)
                {
                    ecran->setColor(COLOR_GREEN);
                    ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                    std::cout<< (char)(y+'A') << x;
                }
                if(select)
                {
                    if(order!=order_save || direction!= direction_save)
                    {
                        ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN+2);
                        std::cout<< "Ordre:               ";
                        order_save=order;
                        direction_save=direction;
                    }
                    ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN+2);
                    std::cout<< " Ordre: " << (order==1 ? "move" : order==0? "turn only" : "remove");
                    if(order!= 2)
                    {
                        switch(direction)
                        {
                        case -2:
                            std::cout << " up";
                            break;
                        case -1:
                            std::cout << " left";
                            break;
                        case 2:
                            std::cout << " down";
                            break;
                        case 1:
                            std::cout << " right";
                            break;
                        }
                    }

                }
                else
                {
                    ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN+2);
                    std::cout<< "                       ";
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
                                ecran->setColor(COLOR_GREEN);
                                ecran->gotoLigCol(3, 0);
                                std::cout<<"choix non valide"<<std::endl;
                                t=time(NULL);
                                while(difftime(time(NULL),t)<=2);
                                ecran->gotoLigCol(3, 0);
                                std::cout<<"                "<<std::endl;
                            }
                        }
                        else if((win_test=(buff=board.Getmap(x,y))->push(board, direction, order,0, true))!=-1)
                        {
                            if(win_test==0)
                            {
                                ecran->setColor(COLOR_GREEN);
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"Quelle est la direction de la piece?";
                                turnPiece(buff,ecran);
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"                                      ";
                            }
                            ecran->setColor(COLOR_GREEN);
                            ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            std::cout<<"                                 ";
                            board.boardCons(ecran);
                            board.display(NULL,0,ecran);
                            test=0;
                            boucle=0;
                        }
                        else
                        {
                            ecran->setColor(COLOR_GREEN);
                            ecran->gotoLigCol(DECALAGE_X_TEXT-3, DECALAGE_Y_TEXT+BOARD_HEIGHT);
                            std::cout<<"                                  "<<std::endl;
                            std::cout<<"                                  "<<std::endl;
                            ecran->gotoLigCol(DECALAGE_X_TEXT-2, DECALAGE_Y_TEXT+BOARD_HEIGHT);
                            std::cout<<"Mouvement impossible, selectionnez une autre action";
                            time_t timer=time(NULL);
                            while(difftime(time(NULL), timer)<2);
                            ecran->gotoLigCol(DECALAGE_X_TEXT-2, DECALAGE_Y_TEXT+BOARD_HEIGHT);
                            std::cout<<"                                                                           "<<std::endl;
                            select=0;
                        }
                        break;
                    case 27: //escape
                        if(!select)
                        {
                            test=0;
                            ecran->setColor(COLOR_GREEN);
                            ecran->gotoLigCol(DECALAGE_X_TEXT, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            std::cout<<"   "; //EXIT BOUCLE SELECTION CASE, RETOUR CHOIX DE L'ACTION
                        }
                        else select=0;
                    case 'z':
                    case 'Z':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(y>0)
                        {
                            if(!select) y--;
                        }
                        direction=-2;
                        test2=1;

                        break;
                    case 'q':
                    case 'Q':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x>0)
                        {
                            if(!select) x--;
                        }
                        direction=-1;
                        test2=1;
                        break;
                    case 's':
                    case 'S':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if (y+1<BOARD_HEIGHT)
                        {
                            if(!select) y++;

                        }
                        direction=2;
                        test2=1;

                        break;

                    case 'd':
                    case 'D':
                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x+1<BOARD_WIDTH)
                        {
                            if(!select) x++;
                        }
                        direction=1;
                        test2=1;
                        break;

                    case ' ':
                        if(select) order = (!order ?  1 : order==1 ? ((x==0 || x==BOARD_WIDTH-1 || y==0 || y==BOARD_HEIGHT-1) ? 2 : 0) : 0);
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
        else
        {
            test=0;
            time_t t=time(NULL);
            ecran->showCursor(false);
            while(!test)
            {
                ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                if(test2)
                {
                    ecran->setColor(COLOR_WHITEANDBLACK);
                    if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                    else std::cout <<"  ";
                }
                else
                {
                    ecran->setColor(COLOR_NDEFAULT);
                    if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                    else std::cout <<"  ";
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
                            ecran->setColor(COLOR_GREEN);
                            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            std::cout<<"                                      ";
                            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            std::cout<<"Quelle est la direction de la piece?";
                            turnPiece(m_stockPiece.top(),ecran);
                            ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                            std::cout<<"                                      ";
                            m_stockPiece.pop();
                            ecran->setColor(COLOR_NDEFAULT);
                            ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                            if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                            else std::cout <<"  ";
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
                                ecran->setColor(COLOR_GREEN);
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"                                      ";
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"Quelle est la direction de la piece?";
                                turnPiece(m_stockPiece.top(),ecran);
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"                                      ";

                            }
                            buff=m_stockPiece.top(); //AU CAS OU ON SORS UNE PIECE DU MEME JOUEUR
                            if((win_test=board.Getmap(x,y)->push(board, buff->GetOrientation(), 1, buff->Getstrength(), false))!=-1)
                            {
                                board.Setmap(x,y, buff);
                                buff->Setstate(true);
                                m_stockPiece.pop();
                                board.boardCons(ecran);
                                board.display(NULL,0,ecran);
                                test=1;
                                boucle=0;
                            }
                            else
                            {
                                ecran->setColor(COLOR_GREEN);
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"                                      ";
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"Mouvement impossible!";
                                t=time(NULL);
                                while(difftime(time(NULL),t)<=0.5);
                                ecran->gotoLigCol(0, DECALAGE_Y_TEXT+BOARD_HEIGHT+MARGIN);
                                std::cout<<"                                      ";
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
                    case 'Z':


                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(y>0 && (x==0 || x==BOARD_WIDTH-1) && !select) y--;
                        break;


                    case 'q':
                    case 'Q':


                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x>0 && (y==0 || y==BOARD_HEIGHT-1) && !select) x--;
                        break;

                    case 's':
                    case 'S':

                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if (y+1<BOARD_HEIGHT && (x==0 || x==BOARD_WIDTH-1) && !select) y++;
                        break;

                    case 'd':
                    case 'D':

                        ecran->setColor(COLOR_NDEFAULT);
                        ecran->gotoLigCol((MULTIPLICATOR)*y+(y+1)+MULTIPLICATOR/2+MARGINBOARDY,(2*(MULTIPLICATOR)*x)+x+MULTIPLICATOR+MARGINBOARDX);
                        if(board.Getmap(x,y)!=NULL) std::cout<<board.Getmap(x,y)->Getstring();
                        else std::cout <<"  ";
                        ecran->setColor(COLOR_WHITEANDBLACK);
                        if(x+1<BOARD_WIDTH &&(y==0 || y==BOARD_HEIGHT-1) && !select) x++;
                        break;
                        ecran->setColor(COLOR_WHITEANDBLACK);
                    }
                }


                ///FAIRE RENTRER UNE PIECE
            }

        }
    }
    ecran->showCursor(true);

    return (win_test==1 || win_test==2 ? 0 : win_test); //SI win_test==1 ou 2 le win n'est pas apparu, c'est juste que le mouvement s'est fait, il faut qu'il vaille 3 ou 4 pour que ça soit significatif
}


int Player::Play(unsigned int display_mode, BoardGame& board, Console* ecran, Graphic* Pgraph)
{

    if(!display_mode) return(Play_console(board, ecran));
    else return(Play_alleg(board, Pgraph));

}

////////////////////////////////////////////////////
// ENTREE: x/y correspondant a l'écran
// SORTIE: x/y correspondant au tableau
//
///////////////////////////////////////////////////
int Player::screen_to_board_x(int x)
{
    for(int i=0; i<BOARD_WIDTH; i++) if(x<BOARD_X_BLIT+GRID_DECAL+(i+1)*TILE_SIZE) return i;
    return BOARD_WIDTH-1;
}
int Player::screen_to_board_y(int y)
{
    for(int i=0; i<BOARD_HEIGHT; i++) if(y<BOARD_Y_BLIT+GRID_DECAL+(1+i)*TILE_SIZE) return i;
    return BOARD_HEIGHT-1;
}
////////////////////////////////////////////////////
// ENTREE: x/y correspondant au tableau           //
// SORTIE: x/y correspondant a l'écran            //
//                                                //
////////////////////////////////////////////////////
int Player::board_to_screen_x(int x)
{
    return BOARD_X_BLIT+GRID_DECAL+x*TILE_SIZE;
}

int Player::board_to_screen_y(int y)
{
    return BOARD_Y_BLIT+GRID_DECAL+y*TILE_SIZE;
}


int Player::get_rotate(Piece* piece, Graphic* Pgraph)
{
    mouse_b=0;
    int boucle=1;
    BITMAP* save_screen=create_bitmap(Pgraph->Getbuff()->w,Pgraph->Getbuff()->h);
    display_piece(piece,Pgraph);
    blit(Pgraph->Getbuff(), save_screen,0,0,0,0, SCREEN_W, SCREEN_H);
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetUp(), board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetUp()->w)/2, board_to_screen_y(piece->Gety())-Pgraph->GetUp()->h);
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetLeft(), board_to_screen_x(piece->Getx())-Pgraph->GetLeft()->w, board_to_screen_y(piece->Gety())+(TILE_SIZE-Pgraph->GetLeft()->h)/2);
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetDown(), board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetDown()->w)/2, board_to_screen_y(piece->Gety())+ (piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->h : Pgraph->GetEle()->h));
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetRight(), board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w), board_to_screen_y(piece->Gety())+(TILE_SIZE-Pgraph->GetRight()->h)/2);
    blit(Pgraph->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
    while(boucle)
    {
        if(mouse_b&2) boucle=0;
        if(mouse_b&1)
        {
            if(mouse_x<board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetUp()->w)/2+Pgraph->GetUp()->w
                    && mouse_x>=board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetUp()->w)/2
                    && mouse_y>board_to_screen_y(piece->Gety())-Pgraph->GetUp()->h
                    && mouse_y<board_to_screen_y(piece->Gety()))
                    {
                        blit( save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
                        destroy_bitmap(save_screen);
                        std::cout<<"HAUT";
                        return -2;
                    }
            else if(mouse_x>board_to_screen_x(piece->Getx())-Pgraph->GetLeft()->w
                    && mouse_x<board_to_screen_x(piece->Getx())
                    && mouse_y>board_to_screen_y(piece->Gety())+(TILE_SIZE-Pgraph->GetLeft()->h)/2
                    && mouse_y<board_to_screen_y(piece->Gety())+(TILE_SIZE-Pgraph->GetLeft()->h)/2+Pgraph->GetLeft()->h)
                    {
                        blit( save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
                        destroy_bitmap(save_screen);
                        std::cout<<"GAUCHE";
                        return -1;
                    }
            else if(mouse_x>board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetDown()->w)/2
                    && mouse_x<board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetDown()->w)/2+Pgraph->GetDown()->w
                    && mouse_y>board_to_screen_y(piece->Gety())+ (piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->h : Pgraph->GetEle()->h)
                    && mouse_y<board_to_screen_y(piece->Gety())+ (piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->h : Pgraph->GetEle()->h)+Pgraph->GetDown()->h)
                    {
                        blit( save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
                       destroy_bitmap(save_screen);
                       std::cout<<"BAS";
                        return 2;
                    }
            else if(mouse_x>board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w)
                    && mouse_x<board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w)+Pgraph->GetRight()->w
                    && mouse_y>board_to_screen_y(piece->Gety())+(TILE_SIZE-Pgraph->GetRight()->h)/2
                    && mouse_y<board_to_screen_y(piece->Gety())+(TILE_SIZE-Pgraph->GetRight()->h)/2+Pgraph->GetRight()->h)
                    {
                        blit( save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
                        destroy_bitmap(save_screen);
                        std::cout<<"DROITE";
                        return 1;
                    }
        }
    }
    destroy_bitmap(save_screen);
    return -1;
}

fixed Player::get_angle(int orientation)
{
    switch(orientation)
    {
    case 1:
        std::cout<<"DROITE ANGLE"<<std::endl;
        return itofix(192);
        break;
    case 2:
        std::cout<<"BAS ANGLE"<<std::endl;
        return itofix(0);
        break;
    case -1:
        std::cout<<"GAUCHE ANGLE"<<std::endl;
        return itofix(64);
        break;
    case -2:
        std::cout<<"HAUT ANGLE"<<std::endl;
        return itofix(128);
        break;
    }
    return 0;
}
void Player::display_piece(Piece* piece, Graphic* Pgraph)
{
    std::cout<<get_angle(piece->GetOrientation());
    rotate_sprite( Pgraph->Getbuff(),(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn() :(piece->Getteam()==ELEPHANT? Pgraph->GetEle() : Pgraph->GetMnt()) ), board_to_screen_x(piece->Getx()), board_to_screen_y(piece->Gety()), get_angle(piece->GetOrientation()));
}

int Player::get_action(Piece* piece, Graphic* Pgraph)
{
    mouse_b=0;
    if(piece)
    {
    int select=-1;
    BITMAP* save_screen=create_bitmap(Pgraph->Getbuff()->w,Pgraph->Getbuff()->h);
    display_piece(piece,Pgraph);
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetRight(),board_to_screen_x(piece->Getx())-Pgraph->GetRight()->w,board_to_screen_y(piece->Gety())-Pgraph->GetRight()->h );
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetTurn(),board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetTurn()->w)/2,board_to_screen_y(piece->Gety())-Pgraph->GetTurn()->h );
    draw_sprite(Pgraph->Getbuff(),Pgraph->GetUp(),board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w),board_to_screen_y(piece->Gety())-Pgraph->GetUp()->h);
    blit(Pgraph->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
    blit(Pgraph->Getbuff(),save_screen,0,0,0,0, SCREEN_W, SCREEN_H);
    while(select==-1)
    {
        if(mouse_x>board_to_screen_x(piece->Getx())-Pgraph->GetRight()->w
                && mouse_x<board_to_screen_x(piece->Getx())-Pgraph->GetRight()->w+Pgraph->GetRight()->w
                && mouse_y>board_to_screen_y(piece->Gety())-Pgraph->GetRight()->h
                && mouse_y<board_to_screen_y(piece->Gety()))
        {
            textout_ex(Pgraph->Getbuff(),font,"MOVE",board_to_screen_x(piece->Getx())-Pgraph->GetRight()->w+(Pgraph->GetRight()->w-text_length(font,"MOVE"))/2,board_to_screen_y(piece->Gety())-Pgraph->GetRight()->h-text_height(font),COLOR_VERT,COLOR_BLANC);
            blit(Pgraph->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
            blit(save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
            if(mouse_b&1)
            {
                destroy_bitmap(save_screen);
                return 2;
            }
        }
        if(mouse_x>board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetTurn()->w)/2
                && mouse_x<board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetTurn()->w)/2+Pgraph->GetTurn()->w
                && mouse_y>board_to_screen_y(piece->Gety())-Pgraph->GetTurn()->h
                && mouse_y<board_to_screen_y(piece->Gety()))
        {
            textout_ex(Pgraph->Getbuff(),font,"TURN",board_to_screen_x(piece->Getx())+(TILE_SIZE-Pgraph->GetTurn()->w)/2+(Pgraph->GetTurn()->w-text_length(font,"TURN"))/2,board_to_screen_y(piece->Gety())-Pgraph->GetTurn()->h-text_height(font),COLOR_VERT,COLOR_BLANC);
            blit(Pgraph->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
            blit(save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
            if(mouse_b&1)
            {
                destroy_bitmap(save_screen);
                return 1;
            }
        }
        if(mouse_x>board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w)
           && mouse_x<board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w)+Pgraph->GetUp()->w
           && mouse_y>board_to_screen_y(piece->Gety())-Pgraph->GetUp()->h
           && mouse_y<board_to_screen_y(piece->Gety())
           && (piece->Getx()==0 || piece->Getx()==BOARD_WIDTH-1 || piece->Gety()==0 || piece->Gety()==BOARD_HEIGHT-1))
            {
            textout_ex(Pgraph->Getbuff(),font,"REMOVE",board_to_screen_x(piece->Getx())+(piece->Getteam()==RHINOCEROS? Pgraph->GetRhn()->w : Pgraph->GetEle()->w)+(Pgraph->GetUp()->w-text_length(font,"REMOVE"))/2,board_to_screen_y(piece->Gety())-Pgraph->GetUp()->h-text_height(font),COLOR_VERT,COLOR_BLANC);
            blit(Pgraph->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
            blit(save_screen,Pgraph->Getbuff(),0,0,0,0, SCREEN_W, SCREEN_H);
            if(mouse_b&1)
            {
                destroy_bitmap(save_screen);
                return 0;
            }
        }

    }
    }
    return -1;
}



/////////////////////////////////////////////////
// Fonction de jeu allegro                     //
//                                             //
//                                             //
//                                             //
/////////////////////////////////////////////////
int Player::Play_alleg(BoardGame& board, Graphic* Pgraph)
{
    int test=0;
    int x=0,y=0;
    int select=0;
    int win_test=0;
    Piece* buff;
    mouse_b=0;
    BITMAP* save_screen=create_bitmap(SCREEN_W, SCREEN_H);
    textout_ex(Pgraph->Getbuff(), font, "                                                                            ", 2,3, COLOR_VERT, makecol(0,0,0));
    textprintf_ex(Pgraph->Getbuff(), font, 2,3, COLOR_VERT, -1, (m_team==1 ? "TOUR RHINO Pieces restantes: %d": "TOUR ELEPHANT Pieces restantes: %d")    , m_stockPiece.size());
    blit(Pgraph->Getbuff(),save_screen,0,0,0,0, SCREEN_W, SCREEN_H);
    blit(Pgraph->Getbuff(),screen,0,0,0,0, SCREEN_W, SCREEN_H);
    show_mouse(screen);
    while(!test)
    {
        mouse_b=0;
        x=screen_to_board_x(mouse_x);
        y=screen_to_board_y(mouse_y);
        while(!mouse_b&1)
        {
            scare_mouse();
            x=screen_to_board_x(mouse_x);
            y=screen_to_board_y(mouse_y);
            if((m_stockPiece.size()==NB_PIONS_PLAYER &&(x==0 || x==BOARD_WIDTH-1 || y==0 || y== BOARD_HEIGHT-1))|| m_stockPiece.size()!=NB_PIONS_PLAYER)
            {
                draw_sprite(Pgraph->Getbuff(),Pgraph->GetSel(),board_to_screen_x(x), board_to_screen_y(y));
                blit(Pgraph->Getbuff(), screen, 0,0,0,0, SCREEN_W, SCREEN_H);
                blit(save_screen, Pgraph->Getbuff(), 0,0,0,0, SCREEN_W, SCREEN_H);
            }
            else blit(Pgraph->Getbuff(), screen, 0,0,0,0, SCREEN_W, SCREEN_H);
            show_mouse(screen);

        }

        if(!board.Getmap(x,y))
        {
            if(x==0 || x==BOARD_WIDTH-1 || y==0 || y==BOARD_HEIGHT-1)
            {
                if(m_stockPiece.size())
                {
                    board.Setmap(x,y, m_stockPiece.top());
                    m_stockPiece.top()->Setstate(true);
                    m_stockPiece.top()->SetOrientation(get_rotate(board.Getmap(x,y), Pgraph));
                    m_stockPiece.pop();
                    test=1;
                    blit(save_screen, Pgraph->Getbuff(), 0,0,0,0, SCREEN_W, SCREEN_H);
                    display_piece(board.Getmap(x,y), Pgraph);
                    blit(Pgraph->Getbuff(),screen, 0,0,0,0, SCREEN_W, SCREEN_H);
                }
                else allegro_message("Plus de pieces!");
            }
            else
            {
                allegro_message("Choix non valide");
            }
        }
        else if(auth_check(x,y,board))
        {
            if((select=get_action(board.Getmap(x,y), Pgraph))==1) //TURN ONLY
            {
                blit(save_screen, Pgraph->Getbuff(), 0,0,0,0, SCREEN_W, SCREEN_H);
                board.Getmap(x,y)->SetOrientation(get_rotate(board.Getmap(x,y), Pgraph));
                test=1;
            }
            else if(select==2) // MOVE
            {
                blit(save_screen, Pgraph->Getbuff(), 0,0,0,0, SCREEN_W, SCREEN_H);
                if((win_test=(buff=board.Getmap(x,y))->push(board,get_rotate(board.Getmap(x,y), Pgraph), 1, 0, true))!=-1)
                {
                    if(win_test==0)
                    {
                        board.alleg_display(Pgraph, this);
                        buff->SetOrientation(get_rotate(buff, Pgraph));
                    }
                    test=1;
                }

            }
            else //REMOVE
            {
                blit(save_screen, Pgraph->Getbuff(), 0,0,0,0, SCREEN_W, SCREEN_H);
                board.Getmap(x,y)->push(board,0, 2, 0, true);
                blit(Pgraph->GetBoard(),Pgraph->Getbuff(), board_to_screen_x(x)-BOARD_X_BLIT, board_to_screen_y(y)-BOARD_Y_BLIT,board_to_screen_x(x), board_to_screen_y(y), TILE_SIZE, TILE_SIZE);
                blit(Pgraph->Getbuff(),screen, 0,0,0,0, SCREEN_W, SCREEN_H);
                test=1;
            }
        }
        else if(x==0 || x==BOARD_WIDTH-1 || y==0 || y==BOARD_HEIGHT-1)
        {
            if(m_stockPiece.size()) //AJOUT EN POUSSANT
            {
                if(x!=0 && x!=BOARD_WIDTH-1) m_stockPiece.top()->SetOrientation(y? -2: 2);
                        else if(y!=0 && y!=BOARD_HEIGHT-1) m_stockPiece.top()->SetOrientation(x? -1: 1);
                        else m_stockPiece.top()->SetOrientation(get_rotate(board.Getmap(x,y), Pgraph));

                if((win_test=board.Getmap(x,y)->push(board, m_stockPiece.top()->GetOrientation(), 1, m_stockPiece.top()->Getstrength(), false))!=-1)
                        {
                            board.Setmap(x,y, m_stockPiece.top());
                            m_stockPiece.top()->Setstate(true);
                            m_stockPiece.pop();
                            test=1;
                        }
                        else
                        {
                            allegro_message("Choix non valide");
                            mouse_b=0;
                        }
            }
        }
        else {
                allegro_message("Choix non valide");
                mouse_b=0;
        }
    }
    scare_mouse();
    destroy_bitmap(save_screen);
    return (win_test==1 || win_test==2 ? 0 : win_test);
}

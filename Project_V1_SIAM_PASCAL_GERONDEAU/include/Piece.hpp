#ifndef PIECE_HPP
#define PIECE_HPP

#define BITMAP int


class Piece
{
    public:
        Piece();
        virtual ~Piece();
        Piece(const Piece& other);
        unsigned short Getx() ;
        void Setx(unsigned short val);
        unsigned short Gety() ;
        void Sety(unsigned short val) ;
        unsigned short Getstrength() ;
        void Setstrength(unsigned short val) ;
        bool Getstate() ;
        void Setstate(bool val);
        BITMAP* GetimgPiece();
        void SetimgPiece(BITMAP* val);
    protected:
    private:
        unsigned short m_x;
        unsigned short m_y;
        unsigned short m_strength;
        bool m_state;
        BITMAP* m_imgPiece;
};

#endif // PIECE_HPP

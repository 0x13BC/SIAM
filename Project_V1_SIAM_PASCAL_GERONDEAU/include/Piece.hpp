#ifndef PIECE_HPP
#define PIECE_HPP

#define BITMAP int


class Piece
{
    public:
        Piece();
        virtual ~Piece();
        Piece(const Piece& other);
        unsigned short Getx() { return m_x; }
        void Setx(unsigned short val) { m_x = val; }
        unsigned short Gety() { return m_y; }
        void Sety(unsigned short val) { m_y = val; }
        unsigned short Getstrength() { return m_strength; }
        void Setstrength(unsigned short val) { m_strength = val; }
        bool Getstate() { return m_state; }
        void Setstate(bool val) { m_state = val; }
        BITMAP* GetimgPiece() { return m_imgPiece; }
        void SetimgPiece(BITMAP* val) { m_imgPiece = val; }
    protected:
    private:
        unsigned short m_x;
        unsigned short m_y;
        unsigned short m_strength;
        bool m_state;
        BITMAP* m_imgPiece;
};

#endif // PIECE_HPP

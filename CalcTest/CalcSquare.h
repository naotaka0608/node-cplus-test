class CalcSquare
{
private:
    double m_h;
    double m_w;

    double m_area;

public:
    CalcSquare();
    ~CalcSquare();
        
    inline void SetHeight(double h) { m_h = h; }
    inline double GetHeight() { return m_h; }

    inline void SetWidth(double w) { m_w = w; }
    inline double GetWidth() { return m_w; }

    void ClacArea();

    inline double GetSquareArea() { return m_area; }

};

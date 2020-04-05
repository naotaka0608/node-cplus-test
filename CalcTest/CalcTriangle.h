#include <windows.h>

class CalcTriangle
{
private:
    double m_b;
    double m_h;

    double m_area;
    
    HMODULE m_hModule;

public:
    CalcTriangle();
    ~CalcTriangle();
        
    inline void SetBottom(double b) { m_b = b; }
    inline double GetBottom() { return m_b; }

    inline void SetHeight(double h) { m_h = h; }
    inline double GetHeight() { return m_h; }

    void ClacArea();

    inline double GetTriangleArea() { return m_area; }

};
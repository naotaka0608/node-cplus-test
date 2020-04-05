#include "./CalcTriangle.h"

typedef double(*FUNC)(double, double);

CalcTriangle::CalcTriangle()
{
    m_b = 0;
    m_h = 0;
    m_area = 0;

    m_hModule = NULL;
}

CalcTriangle::~CalcTriangle()
{
    if(m_hModule != NULL) ::FreeLibrary(m_hModule);
}

void CalcTriangle::ClacArea()
{
    double bottom, height, ans;

    bottom = m_b;
    height = m_h;

    m_hModule = LoadLibraryA("CalcTriangleLib.dll");
    if (NULL != m_hModule) {
        FUNC CalcTriangle = (FUNC)GetProcAddress(m_hModule, "CalcTriangle");
        if (CalcTriangle) {
            ans = CalcTriangle(bottom, height);
        }else{
            ans = -9999;
        }

        ::FreeLibrary(m_hModule);
        m_hModule = NULL;
    }else{
        ans = -9999;
    }

    m_area = ans;

    return;
}

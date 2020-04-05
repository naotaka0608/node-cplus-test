#include "./CalcSquare.h"

CalcSquare::CalcSquare()
{
    m_h = 0;
    m_w = 0;
    m_area = 0;
}

CalcSquare::~CalcSquare()
{

}

void CalcSquare::ClacArea()
{
    m_area = m_h * m_w;
}

#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
namespace pp
{
    class Vselennaya
    {
    public:
        Vselennaya(int x0, int y0, int spacing, int vector)
        {
            {
                if (vector > 1)
                {
                    vector = 1;
                }
                if (vector < -1 || vector == 0)
                {
                    vector = -1;
                }
                m_vector = vector;
                m_x0 = x0;
                m_y0 = y0;
                m_spacing = spacing;
            }
        }
        // x0, y0 - координаты солнца , spacing - расстояние от солнца , vector - направление вращ
        Vselennaya(int spacing, int vector)
        {
            {
                if (vector > 1)
                {
                    vector = 1;
                }
                if (vector < -1 || vector == 0)
                {
                    vector = -1;
                }
                m_vector = vector;
                m_spacing = spacing;
            }
        }
        int getX() // возвращает координаты вращения планеты
        {
            {
                return m_x;
            }
        }
        int getY()
        {
            {
                return m_y;
            }
        }
        void moving(double vrash) // Каждую итерацию изменяет угол положения планеты на vrash  т. е задаем "приблизительную скорость" 
        {
            {
                m_angle += vrash;
                if (m_angle > 360)
                {
                    m_angle = 0;
                }
                m_x = m_x0 + m_spacing * cos(m_angle * M_PI / 180);
                m_y = m_y0 + m_spacing * sin(m_angle * M_PI / 180) * m_vector;

            }
        }
        void setposition(int x0, int y0) // текущие координаты
        {
            {
                m_x0 = x0;
                m_y0 = y0;
            }
        }
    private:
        int m_x0 = 0, m_y0 = 0, m_spacing = 0, m_x = 0, m_y = 0, m_vector = 1;
        double m_angle = 0;
    };
}
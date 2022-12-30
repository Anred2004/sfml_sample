#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
namespace pp
{
    class Vselennaya
    {
    public:
        Vselennaya(int x0, int y0, int spacing, int vector);
        // x0, y0 - координаты солнца , spacing - расстояние от солнца , vector - направление вращ
        Vselennaya(int spacing, int vector);
        int getX(); // возвращает координаты вращения планеты
        int getY();
        void moving(double vrash); // Каждую итерацию изменяет угол положения планеты на vrash  т. е задаем "приблизительную скорость" 
        void setposition(int x0, int y0); // текущие координаты
    private:
        int m_x0 = 0, m_y0 = 0, m_spacing = 0, m_x = 0, m_y = 0, m_vector = 1;
        double m_angle = 0;
    };
}
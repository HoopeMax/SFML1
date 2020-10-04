//вторая ветвь 
#include <SFML/Graphics.hpp>
#include <cmath>
#include<iostream>
//размер окна
const float width = 1000; //ширина 
const float height = 600; //длина 
class Point_Figure
{
public://точка расположение в центре экрана 
    float a = width / 2.7;
    float b = height / 1.9;
    float a1 = width / 2;
    float b1 = height / 1.2;
};
class Line_Figure: public Point_Figure
{
public:
 //размер фигуры от заданной точки 
int rectH = (1);
int rectW = (100);
int rectB = (50);

}; 
class Object:public Line_Figure 
{
public:
    sf::RectangleShape figure, figure1, figure2, figure3;
    //Позиция и размер фигуры
    Object()
    {
        sf::RectangleShape object(sf::Vector2f(rectW, rectH));
        sf::RectangleShape object1(sf::Vector2f(rectW, rectH));
        sf::RectangleShape object2(sf::Vector2f(rectH, rectB));
        sf::RectangleShape object3(sf::Vector2f(rectH, rectB));
        object.setFillColor(sf::Color(255, 0, 0));
        object1.setFillColor(sf::Color(255, 0, 0));
        object2.setFillColor(sf::Color(255, 0, 0));
        object3.setFillColor(sf::Color(255, 0, 0));
        figure = object;
        figure1 = object1;
        figure2 = object2;
        figure3 = object3;
        float x, y, speed;
        bool flag(true);
    }
    //Движение объекта в центре экрана по синусоиде
    void moving(float t)
    {
        x = 50;
        y = 0;
        speed = 0;
        if (a + 450 <= width && flag)//ограниечение справа
        {
            speed = t;
            a += x * speed;
            y = cos(a * (3, 14) / 180) * 250;
            b -= y * speed;
        }
        else flag = false;
        if (a >= 270 && !flag)//ограничение слева
        {
            speed = t;
            a -= x * speed;
            y = cos(a * (3, 14) / 180) * 250;
            b += y * speed;
        }
        else flag = true;
        speed = 0;
        figure.setPosition(a, b);

    }
   
};
class Pathway
{
public:
    sf::VertexArray point;
    Pathway()
    {
        sf::VertexArray p(sf::Points, 2500);
        point = p;
    }
    void array_point()
    {
        //начало траектории
        double x = 5.2;
        double n = 0.24; // плотность кривой
        int H = height - 660; // высота кривой
        double d = 0.02; // плотность точек
        for (int i = 1290; i < 2340; i++)
        {
            point[i].position = sf::Vector2f(i * n, height / 2 - H * sin(x));
            point[i].color = sf::Color(255, 0, 0);
            x += d;
        }
        //конец траектории
    }
};
void input();
//Движение объекта в центре экрана по синусоиде

int main()
{
    input();
    return 0;
}

void input()
{
    //название окна
    sf::RenderWindow window(sf::VideoMode(width, height), "Laboratory work 1 ( option 13) ");
    Object* lastRect = new Object;
    Pathway* poi = new Pathway;
    //Object lastRect;
    //Pathway poi;
    sf::Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        moving(time);
        poi->array_point();
        /* lastRect.moving(time);
         poi.array_point();*/
        window.clear(sf::Color(0, 0, 0));
        for (int i = 1290; i < 2340; i++)
        {
            window.draw(poi->point);
            //window.draw(poi.point);
        }
        window.draw(lastRect->figure);
   
        //window.draw(lastRect.figure);
        window.display();

    }
}
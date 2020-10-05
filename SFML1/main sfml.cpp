
//вторая ветвь 
#include <SFML/Graphics.hpp>
#include <cmath>
#include<iostream>

//размер окна
const float width = 1000; //ширина 
const float height = 600; //длина 

class Point_Figure
{
protected:
    //координаты 
    float a = width / 2.7;
    float b = height / 1.9;

    //размеры 
    int rectH = (2);
    int rectW = (100);
    int rectB = (50);
};
class Line_Figure: public Point_Figure
{
public:
    sf::RectangleShape figure, figure1, figure2, figure3;//линии

    Line_Figure()
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
    }


}; 
class Object:public Line_Figure 
{
public:

    sf::RectangleShape mainfigure;
    float x=50, y=0, speed=0;
    bool flag;
 
    Object()
    {
  
        sf::RectangleShape mainobject(sf::Vector2f(rectW-2, rectB-2));

        mainobject.setFillColor(sf::Color(0, 0, 250));

        mainfigure = mainobject;
        
    }
    //Движение объекта в центре экрана по синусоиде
    void moving(float t)
    {
      
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
        figure1.setPosition(a, b+50); 
        figure2.setPosition(a+100, b);
        figure3.setPosition(a, b);
        mainfigure.setPosition(a+2, b+2);
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
    //void array_point()
    //{
    //    //начало траектории
    //    double x = 5.2;
    //    double n = 0.25; // плотность кривой
    //    int H = height - 660; // высота кривой
    //    double d = 0.02; // плотность точек
    //    for (int i = 1290; i < 2340; i++)
    //    {
    //        point[i].position = sf::Vector2f(i * n, height / 2 - H * sin(x));
    //        point[i].color = sf::Color(255, 0, 0);
    //        x += d;
    //    }
    //    //конец траектории
    //}
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


        lastRect->moving(time);
        //poi->array_point();


        window.clear(sf::Color(0, 0, 0));
        for (int i = 1290; i < 2340; i++)
        {
            window.draw(poi->point);

        }

      //рисуются объекты
        window.draw(lastRect->figure);
        window.draw(lastRect->figure1);
        window.draw(lastRect->figure2);
        window.draw(lastRect->figure3);
        window.draw(lastRect->mainfigure);

        window.display();
    }

    delete lastRect;
    delete poi;
}
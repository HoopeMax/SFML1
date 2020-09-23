#include <SFML/Graphics.hpp>
#include <cmath>

//размер окна
const float width = 1000; //ширина 
const float height = 600; //длина 
//размер фигуры
int rectH = height / 20;
int rectW = width / 20;

class Object
{
public:
    sf::RectangleShape figure;
    float x, y, speed;
    sf::FloatRect rectangle;
    bool flag;
    //Позиция и размер фигуры
    Object()
    {
       
        sf::RectangleShape object(sf::Vector2f(rectW, rectH));
        object.setFillColor(sf::Color(255, 0, 0));
        figure = object;
        rectangle.width = width / 2.7;
        rectangle.height = height / 1.9;//высота
        x = 50;
        y = 5;
        speed = 0;
    }
   
    //Движение объекта в центре экрана по синусоиде
    void moving(float t)
    {
        if (rectangle.width + 450 <= width && flag)//ограниечение справа
        {
            speed = t;
            rectangle.width += x * speed;
            y = cos(rectangle.width * (3, 14) / 180) * 250;
            rectangle.height -= y * speed;
        }
        else flag = false;
        if (rectangle.width >= 270 && !flag)//ограничение слева
        {
            speed = t;
            rectangle.width -= x * speed;
            y = cos(rectangle.width * (3, 14) / 180) * 250;
            rectangle.height += y * speed;
        }
        else flag = true;
        speed = 0;
        figure.setPosition(rectangle.width, rectangle.height);
    }
};

int main()
{
    //название окна
    sf::RenderWindow window(sf::VideoMode(width, height), "Laboratory work 1 ( option 13) ");
    Object lastRect;
    sf::Clock clock;
    //начало траектории
    sf::VertexArray point(sf::Points, 2500);
    double x = 5.2;
    double n = 0.24; // плотность кривой
    int H = height-660; // высота кривой
    double d = 0.02; // плотность точек
    for (int i = 1290; i < 2340; i++)
    {
        point[i].position = sf::Vector2f(i * n, height / 2 - H * sin(x));
        point[i].color = sf::Color(255, 0, 0);
        x += d;
    }
    //конец траектории
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
        lastRect.moving(time);
        window.clear(sf::Color(0, 0,0));
        window.draw(lastRect.figure);
        window.draw(point);
        window.display();
    }
    return 0;
}

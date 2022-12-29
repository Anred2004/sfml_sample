#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Header.hpp"
using namespace sf;

int main()
{
    float frame = 0;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1800, 1500), L"Vselennaya");
    window.setVerticalSyncEnabled(true);
    sf::VertexArray Point(sf::Points, 500);
    for (int i = 0; i < 500; i++)
    {
        Point[i].position = Vector2f(rand() % 1800, rand() % 1500);
    }
    // Объявление планет солнце, меркурий, венера, земля, марс, луна
    CircleShape Sun(100.f), Mercury(6), Venus(14), Earth(15), Mars(7), Jupiter(55), Saturn(45), Uranus(40), Neptune(35), Moon(2);
    Sun.setPosition(900, 750);
    Sun.setOrigin(100, 100);
    Texture textureSun;
    textureSun.loadFromFile("sun.png");
    Sun.setTexture(&textureSun);

    Texture textureEarth;
    textureEarth.loadFromFile("earth.png");
    Earth.setTexture(&textureEarth);
    Earth.setOrigin(15, 15);

    Texture textureMercury;
    textureMercury.loadFromFile("mercury.png");
    Mercury.setTexture(&textureMercury);
    Mercury.setOrigin(6, 6);

    Texture textureVenus;
    textureVenus.loadFromFile("venus.png");
    Venus.setTexture(&textureVenus);
    Venus.setOrigin(14, 14);

    Texture textureMars;
    textureMars.loadFromFile("mars.png");
    Mars.setTexture(&textureMars);
    Mars.setOrigin(7, 7);

    Texture textureJupiter;
    textureJupiter.loadFromFile("jupiter.png");
    Jupiter.setTexture(&textureJupiter);
    Jupiter.setOrigin(55, 55);

    Texture textureUranus;
    textureUranus.loadFromFile("uran.png");
    Uranus.setTexture(&textureUranus);
    Uranus.setOrigin(40, 40);

    Texture textureNeptune;
    textureNeptune.loadFromFile("neptune.png");
    Neptune.setTexture(&textureNeptune);
    Neptune.setOrigin(35, 35);

    Texture textureSaturn;
    textureSaturn.loadFromFile("saturn.png");
    Saturn.setTexture(&textureSaturn);
    Saturn.setOrigin(45, 45);

    Texture textureMoon;
    textureMoon.loadFromFile("luna.png");
    Moon.setTexture(&textureMoon);
    Moon.setOrigin(2, 2);


    Image image;
    image.loadFromFile("asteroid.png");
    Texture texture;
    texture.loadFromImage(image);
    Sprite asteroid;
    asteroid.setTexture(texture);
    asteroid.setTextureRect(IntRect(0, 0, 400, 150));
    asteroid.setPosition(300, 300);

    // Создаём объекты определения координат планет
    pp::Vselennaya Mercury1(900, 750, 115, -10);
    pp::Vselennaya Venus1(900, 750, 150, -1);
    pp::Vselennaya Earth1(900, 750, 200, -1);
    pp::Vselennaya Mars1(900, 750, 250, -1);
    pp::Vselennaya Jupiter1(900, 750, 350, -1);
    pp::Vselennaya Saturn1(900, 750, 470, -1);
    pp::Vselennaya Uranus1(900, 750, 550, -1);
    pp::Vselennaya Neptune1(900, 750, 700, -1);
    pp::Vselennaya Moon1(30, -1);
    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        time = time / 0.001;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        Mercury1.moving(1);
        Mercury.setPosition(Mercury1.getX(), Mercury1.getY());
        Venus1.moving(0.5);
        Venus.setPosition(Venus1.getX(), Venus1.getY());
        Mars1.moving(0.2);
        Mars.setPosition(Mars1.getX(), Mars1.getY());
        Earth1.moving(0.3);
        Earth.setPosition(Earth1.getX(), Earth1.getY());
        Jupiter1.moving(0.06);
        Jupiter.setPosition(Jupiter1.getX(), Jupiter1.getY());
        Saturn1.moving(0.07);
        Saturn.setPosition(Saturn1.getX(), Saturn1.getY());
        Uranus1.moving(0.05);
        Uranus.setPosition(Uranus1.getX(), Uranus1.getY());
        Neptune1.moving(0.04);
        Neptune.setPosition(Neptune1.getX(), Neptune1.getY());
        Moon1.setposition(Earth.getPosition().x, Earth.getPosition().y);
        Moon1.moving(2);
        Moon.setPosition(Moon1.getX(), Moon1.getY());



        Sun.rotate(-0.05);
        Mercury.rotate(-1);
        Venus.rotate(-0.5);
        Mars.rotate(-0.5);
        Earth.rotate(-0.3);
        Uranus.rotate(-0.2);
        Neptune.rotate(-0.1);
        Saturn.rotate(-0.08);
        Jupiter.rotate(-0.08);


        asteroid.move(1.0 * time, 0.08);
        window.clear();
        window.draw(Point);
        window.draw(Sun);
        window.draw(Mercury);
        window.draw(Venus);
        window.draw(Earth);
        window.draw(Mars);
        window.draw(Saturn);
        window.draw(Uranus);
        window.draw(Neptune);
        window.draw(Jupiter);
        window.draw(Moon);
        window.draw(asteroid);
        window.display();
    }
    return 0;
}
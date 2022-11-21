// Blaster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rocket.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    window.setFramerateLimit(60);
    Ship ship;
    ship.drawTriangle();
    float rotate;
    float x;
    float y;
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        rotate = ship.getRotation();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (ship.getRotation() == 180)
            {
                ship.rotate(0);
            }
            else if (ship.getRotation() > 180)
            {
                ship.rotate(-2);
            }
            else if (ship.getRotation() < 180)
            {
                ship.rotate(2);
            }
            ship.move(-1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (ship.getRotation() == 0)
            {
                ship.rotate(0);
            }
            else if (ship.getRotation() <= 180)
            {
                ship.rotate(-2);
            }
            else if (ship.getRotation() > 180 )
            {
                ship.rotate(2);
            }
            ship.move(1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (ship.getRotation() == 90)
            {
                ship.rotate(0);
            }
            else if (ship.getRotation() > 90)
            {
                ship.rotate(-2);
            }
            else if (ship.getRotation() < 90)
            {
                ship.rotate(2);
            }
            ship.move(0, 1);

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (ship.getRotation() == 270)
            {
                ship.rotate(0);
            }
            else if (ship.getRotation() < 270)
            {
                ship.rotate(-2);
            }
            else if (ship.getRotation() > 270)
            {
                ship.rotate(2);
            }
            ship.move(0,-1);
        }

        window.clear();
        window.draw(ship);
        ship.setOrigin(sf::Vector2f(75, 50));
        window.display();
    }

    return 0;
}
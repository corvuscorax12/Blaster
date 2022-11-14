#include<SFML/Graphics.hpp>
class Ship: public sf::Drawable, public sf::Transformable
{
    sf::VertexArray triangle = sf::VertexArray(sf::LineStrip,6);

public:
    void drawTriangle()
    {

        // define the position of the triangle's points
        triangle[0].position = sf::Vector2f(10.f, 10.f);
        triangle[1].position = sf::Vector2f(100.f, 10.f);
        triangle[2].position = sf::Vector2f(150.f, 55.f);
        triangle[3].position = sf::Vector2f(100.f, 100.f);
        triangle[4].position = sf::Vector2f(10.f, 100.f);
        triangle[5].position = sf::Vector2f(10.f, 10.f);


    }
    // add functions to play with the entity's geometry / colors / texturing...

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

        // apply the texture

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(triangle, states);
    }

};
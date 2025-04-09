#include "Flower.h"


void Flower::draw(sf::RenderTarget& tg, sf::RenderStates states) const
{
    states.transform.translate(position);
    tg.draw(stem, states);
    tg.draw(outerPetals, states);
    tg.draw(innerPetals, states);
    tg.draw(leafLeft, states);
    tg.draw(leafRight, states);
}

Flower::Flower(const sf::Vector2f& pos) : position(pos)
{
    this->position = pos;

    //  Stem (doubled size and position)
    stem.setSize({ 40.0f, 200.0f });
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(sf::Vector2f(180.0f, 400.0f));  // 90 ? 180, 200 ? 400

    //  Outer Petals (doubled radius and position)
    outerPetals.setRadius(100.0f);
    outerPetals.setFillColor(sf::Color::Magenta);
    outerPetals.setPosition(sf::Vector2f(120.0f, 240.0f));  // 60 ? 120, 120 ? 240

    //  Inner Petals (doubled radius and position)
    innerPetals.setRadius(50.0f);
    innerPetals.setFillColor(sf::Color::Yellow);
    innerPetals.setPosition(sf::Vector2f(170.0f, 290.0f));  // 85 ? 170, 145 ? 290

    //  Left Leaf (doubled shape and position)
    leafLeft.setPointCount(4);
    leafLeft.setPoint(0, sf::Vector2f(0.0f, 40.0f));
    leafLeft.setPoint(1, sf::Vector2f(60.0f, 100.0f));
    leafLeft.setPoint(2, sf::Vector2f(80.0f, 80.0f));
    leafLeft.setPoint(3, sf::Vector2f(40.0f, 40.0f));
    leafLeft.setFillColor(sf::Color::Green);
    leafLeft.setPosition(sf::Vector2f(100.0f, 480.0f));  // 50 ? 100, 240 ? 480

    //  Right Leaf (doubled shape and position)
    leafRight.setPointCount(4);
    leafRight.setPoint(0, sf::Vector2f(0.0f, 60.0f));
    leafRight.setPoint(1, sf::Vector2f(60.0f, 40.0f));
    leafRight.setPoint(2, sf::Vector2f(90.0f, 80.0f));
    leafRight.setPoint(3, sf::Vector2f(40.0f, 90.0f));
    leafRight.setFillColor(sf::Color::Green);
    leafRight.setPosition(sf::Vector2f(220.0f, 480.0f));  // 110 ? 220, 240 ? 480

}

void Flower::setPos(const sf::Vector2f& pos)
{
    position = pos;
}

sf::Vector2f Flower::getPos() const
{
    return position;
}

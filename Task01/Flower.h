#pragma once
#include <SFML/Graphics.hpp>

class Flower: public sf::Drawable {
private:
	sf::Vector2f position;
	sf::CircleShape outerPetals;
	sf::CircleShape innerPetals;
	sf::RectangleShape stem;
	sf::ConvexShape leafLeft;
	sf::ConvexShape leafRight;
	virtual void draw(sf::RenderTarget& tg, sf::RenderStates states) const override;
	
	
public:
	Flower(const sf::Vector2f& pos);
	void setPos(const sf::Vector2f& pos);
	sf::Vector2f getPos() const;
};
#include <SFML/Graphics.hpp>
#include "Flower.h"
#include <cmath>

enum class TimeOfDay { Day, Night };

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "Flower");
    window.setFramerateLimit(60);

    Flower flowey(sf::Vector2f(50.f, 0.f));

    sf::CircleShape sun(50.f);
    sun.setFillColor(sf::Color::Yellow);

    sf::CircleShape moon(50.f);
    moon.setFillColor(sf::Color(200, 200, 255));  

    const float phaseDuration = 5.f;
    sf::Clock phaseClock;
    TimeOfDay state = TimeOfDay::Day;

    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float elapsed = phaseClock.getElapsedTime().asSeconds();
        if (elapsed >= phaseDuration)
        {
            phaseClock.restart();
            state = (state == TimeOfDay::Day) ? TimeOfDay::Night : TimeOfDay::Day;
        }

        float t = phaseClock.getElapsedTime().asSeconds() / phaseDuration;

        // for arc across screen, x -> [-r, (windowWidth + r)]
        float r = sun.getRadius(); 
        float startX = -r;
        float endX = window.getSize().x + r;
        float currentX = startX + t * (endX - startX);


        // use cosine to calc arc across sky, start at +pi/2 -> beggining of upward arc
        float baseY = 85.f;
        float amplitude = 75.f;
        float currentY = baseY + amplitude * cos((t * 3.14159f + 3.14159f/2)*1.05);

        if (state == TimeOfDay::Day)
        {
            sun.setPosition(sf::Vector2f(currentX, currentY));
        }
        else
        {
            moon.setPosition(sf::Vector2f(currentX, currentY));
        }

        sf::Color bgColor = (state == TimeOfDay::Day) ? sf::Color::Blue : sf::Color(20, 20, 40);
        window.clear(bgColor);

        window.draw(flowey);
        if (state == TimeOfDay::Day)
            window.draw(sun);
        else
            window.draw(moon);

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
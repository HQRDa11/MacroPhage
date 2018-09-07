#include <SFML/Graphics.hpp>

sf::CircleShape ship_Shape(int posX,int posY,int rayon,int angle)
{
    sf::CircleShape ship(rayon,angle);
    ship.setPosition(posX,posY);
    ship.setFillColor(sf::Color(190,190,190));
    ship.setOutlineColor(sf::Color(240,190,30));
    ship.setOutlineThickness(2);
    return ship;

}
sf::CircleShape asteroid_Shape(int posX,int posY,int rayon,int angle)
{
    sf::CircleShape asteroid(rayon,angle);
    asteroid.setPosition(posX,posY);
    asteroid.setFillColor(sf::Color(132,85,5));
    asteroid.setOutlineColor(sf::Color(0,0,0));
    asteroid.setOutlineThickness(0);
    return asteroid;
}
sf::RectangleShape difficult_Med()
{
        sf::RectangleShape medium(sf::Vector2f(150,30));
        medium.setPosition(5,5);
        medium.setOutlineThickness(3);
        medium.setOutlineColor(sf::Color(250,250,250));
        medium.setFillColor(sf::Color(0,0,0));
        return medium;
}
sf::RectangleShape difficult_Hard()
{
        sf::RectangleShape hard(sf::Vector2f(150,30));
        hard.setPosition(5,37);
        hard.setOutlineThickness(3);
        hard.setOutlineColor(sf::Color(250,250,250));
        hard.setFillColor(sf::Color(0,0,0));
        return hard;
}

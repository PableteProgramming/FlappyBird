#include <SFML/Graphics.hpp>

class Bird
{
private:
    double x, y;
    double velocity;
    sf::Sprite sprite;
public:
    Bird(sf::Sprite, double, double);
};
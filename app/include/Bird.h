#include <SFML/Graphics.hpp>
const double gravity= -1500;

class Bird
{
private:
    double x, y;
    double velocity;
    sf::Sprite sprite;
    void Jump();
public:
    Bird(sf::Sprite, double, double);
    void Move(double);
    void Draw(sf::RenderWindow&);
};
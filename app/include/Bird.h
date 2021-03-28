#include <SFML/Graphics.hpp>
const double gravity= -1500;

class Bird
{
private:
    double x, y;
    double velocity;
    sf::Sprite sprite;
    void Jump(sf::Event&);
    bool isJumping = false;
public:
    Bird(sf::Sprite, double, double);
    void Move(double, sf::Event&);
    void Draw(sf::RenderWindow&);
};
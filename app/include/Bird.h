#include <SFML/Graphics.hpp>
#include <iostream>

const double gravity= -1500;
const int window_width = 600;
const int window_height = 800;

class Bird
{
private:
    double x, y;
    double velocity;
    int width, height;
    sf::Sprite sprite;
    sf::Texture texture;
    void Jump(sf::Event&);
    bool isJumping = false;
    bool dead = false;
public:
    Bird();
    void Move(double, sf::Event&);
    void Draw(sf::RenderWindow&);
    bool isDead() { return dead; };
};
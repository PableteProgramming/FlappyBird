#include <SFML/Graphics.hpp>
#include <iostream>

const double gravity= -1800;
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
    bool isJumping = false;
    bool dead = false;
public:
    Bird();
    void Jump(sf::Event&);
    void Move(double, sf::Event&);
    void Draw(sf::RenderWindow&);
    void Collision(std::vector<std::pair<std::pair<sf::Sprite*, sf::Sprite*>, std::pair<float, float>>>);
    bool isDead() { return dead; };
};
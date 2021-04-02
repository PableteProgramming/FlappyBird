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
    std::vector<sf::Texture> animations;
    sf::Sprite sprite;
    float counter = 0, limit = 0.1;
    int skinIndex;
    bool isJumping = false;
    bool dead = false;
    void PlayAnimation(float);
public:
    Bird();
    void Jump(sf::Event&);
    void Move(double);
    void Draw(sf::RenderWindow&);
    void Collision(std::vector<std::pair<std::pair<sf::Sprite*, sf::Sprite*>, std::pair<float, float>>>);
    bool isDead() { return dead; };
};
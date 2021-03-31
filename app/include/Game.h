#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Game
{
private:
    int score;
    std::vector<std::pair<sf::Sprite*, float>> grounds;
    sf::Texture tBackground;
    sf::Sprite sBackground;
    sf::Texture tGround;
    sf::Sprite sGround;
public:
    Game();
    void DisplayEnvironment(sf::RenderWindow&);
    void MoveGround();
    void MoveTubes();
    void DisplayScore();
};
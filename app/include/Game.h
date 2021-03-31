#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Game
{
private:
    int score;
    // Ground variables
    std::vector<std::pair<sf::Sprite*, float>> grounds;
    sf::Texture tBackground;
    sf::Sprite sBackground;
    sf::Texture tGround;
    sf::Sprite sGround;
    //
    // Tube variables
    std::vector<std::pair<sf::Sprite*, float>> tubes;

public:
    Game();
    void DisplayEnvironment(sf::RenderWindow&);
    void MoveGround();
    void MoveTubes();
    void DisplayScore();
};
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>

class Game
{
private:
    int score;
    sf::Texture tBackground;
    sf::Sprite sBackground;
    // Ground variables
    std::vector<std::pair<sf::Sprite*, float>> grounds;
    sf::Texture tGround;
    //    
    // Tube variables
    std::vector<std::pair<std::pair<sf::Sprite*, sf::Sprite*>, std::pair<float, float>>> tubes;
    sf::Texture tTubes;
    //
public:
    Game();
    void DisplayEnvironment(sf::RenderWindow&);
    void MoveGround();
    void MoveTubes();
    void DisplayScore();
};
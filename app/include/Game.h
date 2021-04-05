#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>

class Game
{
private:
    int score = 0;
    float speed = 200;
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
    sf::Font font;
    sf::Text text;
public:
    Game();
    void DisplayEnvironment(sf::RenderWindow&);
    void MoveGround(float);
    void MoveTubes(float);
    void DisplayScore();
    std::vector<std::pair<std::pair<sf::Sprite*, sf::Sprite*>, std::pair<float, float>>> GetTubes() { return tubes; };
};
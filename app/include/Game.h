#include <SFML/Graphics.hpp>

class Game
{
private:
    int score;
    sf::Texture tBackground;
    sf::Sprite sBackground;
    sf::Texture tGround;
    sf::Sprite sGround;
public:
    Game();
    void DisplayBackground(sf::RenderWindow&);
    void DisplayTubes();
    void DisplayScore();
};
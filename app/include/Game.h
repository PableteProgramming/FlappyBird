#include <SFML/Graphics.hpp>

class Game
{
private:
    int score;
public:
    Game();
    void DisplayBackground();
    void DisplayTubes();
    void DisplayScore();
};
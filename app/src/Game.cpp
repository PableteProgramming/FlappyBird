#include <Game.h>

Game::Game()
{
    tBackground.loadFromFile("resources/images/bg.png");
    sBackground.setTexture(tBackground);
    sBackground.setScale(2.25 * sBackground.getScale().x, 1.7 * sBackground.getScale().y);

    tGround.loadFromFile("resources/images/base.png");
    sGround.setTexture(tGround);
    sGround.setScale(sGround.getScale().x * 2, sGround.getScale().y);
    sGround.setPosition(0, 800 - 112);

    for (int i = 0; i < 3; i++)
        grounds.push_back(std::make_pair(new sf::Sprite(tGround), i * 336));
}

void Game::MoveGround()
{
    if (grounds[0].second + 336 >= 0.0f)
    {
        for (int i = 0; i < grounds.size(); i++)
            grounds[i].second -= 0.05;
    }
    else
    {
        grounds.erase(grounds.begin());
        grounds.push_back(std::make_pair(new sf::Sprite(tGround), 672.0f));
    }
}

void Game::DisplayEnvironment(sf::RenderWindow& w)
{
    w.draw(sBackground);
    for (auto i : grounds)
    {   
        i.first->setPosition(i.second, 800.0f - 112.0f);
        w.draw(*(i.first));
    }
}

void Game::DisplayScore()
{

}
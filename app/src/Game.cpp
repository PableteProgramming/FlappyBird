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
}

void Game::DisplayBackground(sf::RenderWindow& w)
{
    w.draw(sBackground);
    w.draw(sGround);
}

void Game::DisplayScore()
{

}

void Game::DisplayTubes()
{

}
#include <Game.h>

Game::Game()
{
    srand(time(0));

    tBackground.loadFromFile("resources/images/bg.png");
    sBackground.setTexture(tBackground);
    sBackground.setScale(2 * sBackground.getScale().x, 1.4 * sBackground.getScale().y);

    tGround.loadFromFile("resources/images/base.png");

    for (int i = 0; i < 3; i++)
        grounds.push_back(std::make_pair(new sf::Sprite(tGround), i * 336));

    tTubes.loadFromFile("resources/images/pipe2.png");

    tubes.push_back(std::make_pair(std::make_pair(new sf::Sprite(tTubes), new sf::Sprite(tTubes)), std::make_pair(800, rand() % 288 + 200)));
    tubes[tubes.size() - 1].first.first->setPosition(tubes[tubes.size() - 1].second.first, tubes[tubes.size() - 1].second.second);
    tubes[tubes.size() - 1].first.second->setPosition(tubes[tubes.size() - 1].second.first, tubes[tubes.size() - 1].second.second);
    tubes[tubes.size() - 1].first.second->setRotation(180);

    tubes.push_back(std::make_pair(std::make_pair(new sf::Sprite(tTubes), new sf::Sprite(tTubes)), std::make_pair(1100, rand() % 288 + 200)));
    tubes[tubes.size() - 1].first.first->setPosition(tubes[tubes.size() - 1].second.first, tubes[tubes.size() - 1].second.second);
    tubes[tubes.size() - 1].first.second->setPosition(tubes[tubes.size() - 1].second.first, tubes[tubes.size() - 1].second.second);
    tubes[tubes.size() - 1].first.second->setRotation(180);

    font.loadFromFile("resources/fonts/Flappy-Bird.ttf");
    text.setFont(font);
}

void Game::MoveGround(float deltaTime)
{
    if (grounds[0].second + 336 >= 0.0f)
    {
        for (int i = 0; i < grounds.size(); i++)
            grounds[i].second -= speed * deltaTime;
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

    for (auto i : tubes)
    {
        i.first.first->setPosition(i.second.first, i.second.second);
        w.draw(*i.first.first);
        i.first.second->setPosition(i.second.first + 52, i.second.second - 120);
        w.draw(*i.first.second);
    }

    for (auto i : grounds)
    {   
        i.first->setPosition(i.second, 700.0f - 112.0f);
        w.draw(*(i.first));
    }
}

void Game::MoveTubes(float deltaTime)
{
    if (tubes[0].second.first + 52 >= 0)
    {
        for (int i = 0; i < tubes.size(); i++) {
            tubes[i].second.first -= speed * deltaTime;
        }
    }
    else
    {
        tubes.erase(tubes.begin());
        tubes.push_back(std::make_pair(std::make_pair(new sf::Sprite(tTubes), new sf::Sprite(tTubes)), std::make_pair(tubes[tubes.size() - 1].second.first + 300, rand() % 268 + 220)));
        tubes[tubes.size() - 1].first.first->setPosition(tubes[tubes.size() - 1].second.first, tubes[tubes.size() - 1].second.second);
        tubes[tubes.size() - 1].first.second->setPosition(tubes[tubes.size() - 1].second.first, tubes[tubes.size() - 1].second.second);
        tubes[tubes.size() - 1].first.second->setRotation(180);
    }
}
#include <main.h>

int main()
{
    Bird player;
    Game game;

    sf::Clock clock;
    double framerate = 120;
    double totalTimeToPass = 1/120;
    double timePassed = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        double toAdd = clock.restart().asSeconds();
        timePassed += toAdd;

        if(timePassed >= totalTimeToPass){
            player.Move(timePassed, event);
            if (player.isDead())
                window.close();
            timePassed = 0;
            window.clear(sf::Color(0,255,255));
            player.Draw(window);
            window.display();
        }
    }

    window.close();
    return 0;
}


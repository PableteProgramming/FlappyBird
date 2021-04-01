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
            game.DisplayEnvironment(window);
            game.MoveGround();
            game.MoveTubes();
            player.Move(timePassed, event);
            player.Collision(game.GetTubes());
            if (player.isDead())
                window.close();
            timePassed = 0;
            player.Draw(window);
            window.display();
        }
    }

    window.close();
    return 0;
}


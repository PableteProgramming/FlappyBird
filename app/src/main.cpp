#include <main.h>

#ifdef _MSC_VER
#include <windows.h>
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
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

        player.Jump(event);
        if (timePassed >= totalTimeToPass){
            game.DisplayEnvironment(window);
            game.MoveGround(timePassed);
            game.MoveTubes(timePassed);
            player.Move(timePassed);
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


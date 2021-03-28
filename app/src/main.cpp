#include <main.h>

int main()
{
    bool running = true;

    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/bird1.png"))
    {
        std::cout << "Failed to load bird image!" << std::endl;
        return 1;
    }
    
    sf::Sprite bird(texture);


    Bird player(bird, 0, 0);
    Game game;

    sf::Clock clock;
    double framerate=120;
    double totaltimetopass= 1/120;
    double timepassed=0;


    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                running=false;
            }
        }


        double toadd= clock.restart().asSeconds();
        timepassed+=toadd;


        if(timepassed>=totaltimetopass){
            player.Move(timepassed, event);
            if (player.isDead())
                running = false;
            timepassed=0;
            window.clear(sf::Color(0,255,255));
            player.Draw(window);
            window.display();
        }

    }

    window.close();

    return 0;
}


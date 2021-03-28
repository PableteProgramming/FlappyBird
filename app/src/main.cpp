#include <main.h>

int main()
{
    bool running = true;

    sf::Sprite bird;
    sf::Texture texture;
    if (!texture.loadFromFile("resources/images/bird1.png"))
    {
        std::cout << "Failed to load bird image!" << std::endl;
        return 1;
    }
    sf::Sprite bird(texture);


    Bird bird(bird, 0, 0);
    

    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                running=false;
            }
        }
    }

    window.close();

    return 0;
}


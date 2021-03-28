#include <main.h>


int main()
{
    bool running=true;

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


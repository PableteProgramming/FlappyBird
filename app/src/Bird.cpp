#include <Bird.h>

Bird::Bird()
{
    x = y = velocity = 0;

    if (!texture.loadFromFile("resources/images/bird1.png"))
        std::cout << "Failed to load bird image!" << std::endl;

    sprite.setTexture(texture);
    sprite.scale(1.5 * sprite.getScale().x,1.5 * sprite.getScale().y);

    width = sprite.getScale().x;
    height = sprite.getScale().y;
}

void Bird::Move(double deltatime, sf::Event& e){
    Jump(e);
    double newy = (velocity * deltatime) + (0.5 * gravity * deltatime * deltatime);
    velocity = newy/deltatime;
    y -= newy;

    if (y + height > window_height)
        dead = true;
}

void Bird::Draw(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}

void Bird::Jump(sf::Event& e){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if (!isJumping) {
            velocity=300;
            isJumping = true;
        }
    }

    if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Space)
        isJumping = false;
}
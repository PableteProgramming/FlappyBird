#include <Bird.h>

Bird::Bird(sf::Sprite sprite, double x, double y)
{
    this->x = x;
    this->y = y;
    velocity=0;
    this->sprite = sprite;
    this->sprite.scale(1.5 * this->sprite.getScale().x,1.5 * this->sprite.getScale().y);

    width = this->sprite.getScale().x;
    height = this->sprite.getScale().y;
}

void Bird::Move(double deltatime, sf::Event& e){
    Jump(e);
    double newy= (velocity*deltatime)+(0.5*gravity*deltatime*deltatime);
    velocity= newy/deltatime;
    y-=newy;


    if (y + height > window_height)
        dead = true;
}

void Bird::Draw(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}

void Bird::Jump(sf::Event& e){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if (!isJumping)
        {
            velocity=300;
            isJumping = true;
        }
    }

    if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::Space)
        isJumping = false;
}
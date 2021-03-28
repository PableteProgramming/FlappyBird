#include <Bird.h>

Bird::Bird(sf::Sprite sprite, double x, double y)
{
    this->x = x;
    this->y = y;
    velocity=0;
    this->sprite = sprite;
}

void Bird::Move(double deltatime){
    Jump();
    double newy= (velocity*deltatime)+(0.5*gravity*deltatime*deltatime);
    velocity= newy/deltatime;
    y-=newy;
}

void Bird::Draw(sf::RenderWindow& window){
    sprite.setPosition(x,y);
    window.draw(sprite);
}

void Bird::Jump(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        velocity=200;
    }
}
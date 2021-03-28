#include <Bird.h>

Bird::Bird(sf::Sprite sprite, double x, double y)
{
    this->x = x;
    this->y = y;
    
    this->sprite = sprite;
}
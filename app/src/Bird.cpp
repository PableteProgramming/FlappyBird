#include <Bird.h>

Bird::Bird()
{
    for (int i = 0; i < 3; i++) {
        sf::Texture temp;
        int index = i + 1;
        temp.loadFromFile("resources/images/bird" + std::to_string(index) + ".png");
        animations.push_back(temp);
    }

    sf::Texture temp;
    temp.loadFromFile("resources/images/bird2.png");
    animations.push_back(temp);

    skinIndex = 0;

    sprite.setTexture(animations[skinIndex]);
    sprite.scale(1.5 * sprite.getScale().x,1.5 * sprite.getScale().y);

    width = sprite.getScale().x;
    height = sprite.getScale().y;

    x = window_width / 2 - 50;
    y = window_height / 2 - height / 2;
    velocity = 0;
}

void Bird::Move(double deltatime){
    PlayAnimation(deltatime);

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

void Bird::Collision(std::vector<std::pair<std::pair<sf::Sprite*, sf::Sprite*>, std::pair<float, float>>> tubes)
{
    for (auto i : tubes)
    {
        sf::FloatRect tube1(i.first.first->getPosition().x,
                            i.first.first->getPosition().y,
                            i.first.first->getLocalBounds().width,
                            i.first.first->getLocalBounds().height
                        );
        sf::FloatRect tube2(i.first.second->getPosition().x,
                            i.first.second->getPosition().y,
                            -i.first.second->getLocalBounds().width,
                            -i.first.second->getLocalBounds().height 
                        ); // '-' because this tube is rotated so the xy coords are on the other side
        sf::FloatRect bird( sprite.getPosition().x,
                            sprite.getPosition().y,
                            sprite.getLocalBounds().width,
                            sprite.getLocalBounds().height
                        );

        if (tube1.intersects(bird) || tube2.intersects(bird))
            dead = true;
    }
}

void Bird::PlayAnimation(float deltaTime)
{
    counter += deltaTime;

    if (counter >= limit)
    {
        counter = 0;
        if (skinIndex == animations.size() - 1)
            skinIndex = 0;
        else
            skinIndex++;
        sprite.setTexture(animations[skinIndex]);
    }
}
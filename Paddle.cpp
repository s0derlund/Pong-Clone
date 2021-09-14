#include "Paddle.h"

void Paddle::initSprite(std::string path, bool player)
{

    this->sprite = this->loadSprite(path);
    this->sprite.scale(sf::Vector2f(0.5f, 0.5f));

    if(player)
    {
        this->sprite.setPosition(this->position.x, this->position.y - (this->sprite.getGlobalBounds().height / 2));
    }
    else
    {
        this->sprite.setPosition(this->position.x - this->sprite.getGlobalBounds().width, this->position.y - (this->sprite.getGlobalBounds().height / 2));
    }
}

// Constructor
Paddle::Paddle(sf::Vector2f position, std::string path, bool player)
{
    this->position = position;
    this->movementspeed = 400.f;
    this->initSprite(path, player);
}

// Destructor
Paddle::~Paddle()
{

}

// Functions

void Paddle::collision()
{
    // SNYGGA TILL
    sf::FloatRect playerBound = this->sprite.getGlobalBounds();

    if(playerBound.top < 0)
        this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x, 0.f));
            
    else if(playerBound.top > (constant::GLOBAL_WINDOW_HEIGHT - playerBound.height))
        this->sprite.setPosition(sf::Vector2f(this->sprite.getPosition().x, constant::GLOBAL_WINDOW_HEIGHT - playerBound.height));

}

void Paddle::update(const float &dt)
{
    this->collision();
}

void Paddle::render(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

void Paddle::move(const float &dt, sf::Vector2f velocity)
{
    this->sprite.move(velocity.x * this->movementspeed * dt, velocity.y * this->movementspeed * dt);
}

void Paddle::reset()
{

}

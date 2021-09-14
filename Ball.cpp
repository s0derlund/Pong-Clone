#include "Ball.h"


void Ball::initBall()
{
    this->movementspeed = 450.f;
    this->sprite = this->loadSprite("assets/Ball/fireball.png");
    this->sprite.scale(sf::Vector2f(0.13f, 0.13f));
    this->sprite.setPosition(this->position.x - (this->sprite.getGlobalBounds().width / 2), this->position.y - (this->sprite.getGlobalBounds().height / 2));
}

void Ball::initText()
{
    this->cdFont.loadFromFile("assets/Fonts/BalooChettan2-Medium.ttf");
    this->cdText.setFont(this->cdFont);
    this->cdText.setString("2.0");
    this->cdText.setCharacterSize(65);
    this->cdText.setStyle(sf::Text::Bold);
    this->cdText.setFillColor(sf::Color::White);
    this->cdText.setPosition(this->position.x - (this->cdText.getGlobalBounds().width / 2), this->position.y - 50.f);
}

Ball::Ball()
{
    this->position = sf::Vector2f(constant::GLOBAL_WINDOW_WIDTH / 2, constant::GLOBAL_WINDOW_HEIGHT / 2);
    this->direction = sf::Vector2f(0.75f, 1.f);

    this->initBall();
    this->initText();
}

Ball::~Ball()
{
    
}

// Functions

void Ball::collision()
{
    sf::FloatRect ballBounds = this->getSprite().getGlobalBounds();

    // Top Bottom wall
    if(ballBounds.top < 0 || ballBounds.top + ballBounds.width > constant::GLOBAL_WINDOW_HEIGHT)
        this->velocity.y = -this->velocity.y;
}

void Ball::startMomentum()
{
    // Slumpa starthåll
    int randN = rand() % 4 + 1;
    
    switch(randN)
    {
        // Vänster UP
        case 1:
            this->velocity = sf::Vector2f(-this->direction.x, -this->direction.y);
            break;
        // Vänster NER
        case 2:
            this->velocity = sf::Vector2f(this->direction.x, -this->direction.y);
            break;
        // Höger UP
        case 3:
            this->velocity = sf::Vector2f(-this->direction.x, this->direction.y);
            break;
        // Höger NER
        case 4:
            this->velocity = sf::Vector2f(this->direction.x, this->direction.y);
            break;
    }
}

void Ball::update(const float &dt)
{
    this->collision();
    if(this->startTimer(dt))
    {
        this->cdText.setString("");
        this->startMomentum();
        std::cout << "Match!" << std::endl;
    }
    this->move(dt, this->velocity);
}

bool Ball::startTimer(const float &dt)
{
    if(this->cd > 0.0f)
    {
        this->cd -= this->ballMotionTimer.getElapsedTime().asSeconds() * dt;
        if(this->cd <= 0.0f)
            return true;
        this->cdText.setString(std::to_string(round(this->cd * 10) / 10).substr(0, 3));
        return false;
    }
    return false;
}

void Ball::render(sf::RenderWindow &window)
{
    window.draw(this->sprite);
    window.draw(this->cdText);
}

void Ball::move(const float &dt, sf::Vector2f velocity)
{
   if(std::abs(velocity.x) >= maxVelocity)
   {
        if(velocity.x < 0)
            this->velocity.x = -maxVelocity;
        else
            this->velocity.x = maxVelocity;
   }
   this->sprite.move((velocity.x * this->movementspeed) * dt, (velocity.y * this->movementspeed) * dt);
}

void Ball::reset()
{
    this->cd = 1.0;
    this->sprite.setPosition(this->position.x - (this->sprite.getGlobalBounds().width / 2), this->position.y - (this->sprite.getGlobalBounds().height / 2));
    this->velocity = sf::Vector2f(0.f, 0.f);
    this->ballMotionTimer.restart();
}

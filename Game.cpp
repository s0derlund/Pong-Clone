#include "Game.h"
#include "Paddle.h"
#include "Ball.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(constant::GLOBAL_WINDOW_WIDTH, constant::GLOBAL_WINDOW_HEIGHT), "Pong");
    this->window->setPosition(sf::Vector2i(constant::GLOBAL_WINDOW_SCREEN_POS_X, constant::GLOBAL_WINDOW_SCREEN_POS_Y));
    this->window->setVerticalSyncEnabled(false);
}

void Game::initBackground()
{
    this->tbackground.loadFromFile("assets/Background/bg.jpg");
    this->sbackground.setTexture(this->tbackground);
}

void Game::initScoreBoard()
{
    this->scoreboard = new ScoreBoard();
}

void Game::initPlayer()
{
    this->player = new Paddle(sf::Vector2f(10.f,(constant::GLOBAL_WINDOW_HEIGHT / 2)), "assets/Player/spaceship.png", true);
}

void Game::initEnemy()
{
    this->enemy = new Paddle(sf::Vector2f(constant::GLOBAL_WINDOW_WIDTH - 10.f, (constant::GLOBAL_WINDOW_HEIGHT / 2)), "assets/Enemy/spaceship.png", false);
}

void Game::initBall()
{
    this->ball = new Ball();
}

Game::Game()
{
    this->initWindow();
    this->initBackground();
    this->initScoreBoard();
    this->initBall();
    this->initPlayer();
    this->initEnemy();
}

Game::~Game()
{
    delete this->window;
    delete this->scoreboard;
    delete this->ball;
    delete this->player;
    delete this->enemy;
}

void Game::CheckPaddleCollision(Entity *ball, Entity *paddle)
{
    sf::FloatRect paddleBounds = paddle->getSprite().getGlobalBounds();
    sf::FloatRect ballBounds = ball->getSprite().getGlobalBounds();

    float paddleTop = paddleBounds.top + paddleBounds.height - (2.0f * paddleBounds.height / 3.0f);
    float paddleMiddle = paddleBounds.top + paddleBounds.height - (paddleBounds.height / 3.0f);

    if(ballBounds.intersects(paddleBounds))
    {
        // TOP
        if((ballBounds.top + ballBounds.height > paddleBounds.top) && ballBounds.top + ballBounds.height < paddleTop)
            this->ball->setVelocity(sf::Vector2f(-this->ball->getVelocity().x, -.75f));

        // Middle
        else if((ballBounds.top + ballBounds.height > paddleTop) && (ballBounds.top + ballBounds.height < paddleMiddle))
            this->ball->setVelocity(sf::Vector2f(-this->ball->getVelocity().x * 1.1f, 0.f));
        // Bottom
        else
            this->ball->setVelocity(sf::Vector2f(-this->ball->getVelocity().x, .75f));       
    }
}

void Game::checkCollisions()
{
    this->CheckPaddleCollision(this->ball, this->player);
    this->CheckPaddleCollision(this->ball, this->enemy);
    
    // Kirra mål
    if(this->ball->getSprite().getGlobalBounds().left < 0)
    {
        this->scoreboard->setPlayerScore(false);
        this->ball->reset();
    }
    else if(this->ball->getSprite().getGlobalBounds().left + this->ball->getSprite().getGlobalBounds().width > constant::GLOBAL_WINDOW_WIDTH)
    {
        this->scoreboard->setPlayerScore(true);
        this->ball->reset();
    }

}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLev()
{
    while(this->window->pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed)
            this->window->close();
        if(this->event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            this->window->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(this->dt, sf::Vector2f(0.f, -1.f));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(dt, sf::Vector2f(0.f, 1.f));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->enemy->move(dt, sf::Vector2f(0.f, -1.f));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->enemy->move(dt, sf::Vector2f(0.f, 1.f));
}

void Game::update()
{
    this->updateSFMLev();
    this->checkCollisions();
    this->scoreboard->update(this->dt);
    this->ball->update(this->dt);
    this->player->update(this->dt);
    this->enemy->update(this->dt);
}

void Game::render()
{
    this->window->clear();
    
    // Render items
    this->window->draw(sbackground);
    this->scoreboard->render(*window);
    this->ball->render(*window);
    this->player->render(*window);
    this->enemy->render(*window);

    this->window->display();
}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}

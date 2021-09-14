#pragma once
#include "global.h"
#include "Entity.h"
#include "ScoreBoard.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

class Game
{
    private:
        // Varibles
        
        sf::RenderWindow *window;
        sf::Event event;
        sf::Clock dtClock;

        Entity *player;
        Entity *enemy;
        Entity *ball;
        
        ScoreBoard *scoreboard;

        float dt;

        sf::Sprite sbackground;
        sf::Texture tbackground;

        // Static functions
        void initWindow();
        void initBackground();
        void initScoreBoard();
        void initPlayer();
        void initEnemy();
        void initBall();

    public:
        // Constructor/ Destructor
        Game();
        virtual ~Game();
        
        // Functions
        void CheckPaddleCollision(Entity *ball, Entity *paddle);
        void checkCollisions();
        void updateDt();
        void updateSFMLev();
        void update();
        void render();
        void run();

};

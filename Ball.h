#pragma once

#include "Entity.h"

#include <iostream>

class Ball : public Entity
{
    private:
        sf::Vector2f direction;
        float maxVelocity = 2.f;

        float cd = 2.0f;
        bool b_started = false;
        
        sf::Clock ballMotionTimer;
        sf::Font cdFont;
        sf::Text cdText;

        // Init
        void initBall();
        void initText();

    public:
        Ball();
        virtual ~Ball();

        // Functions
        void startMomentum();
        void collision();
        void update(const float &dt);
        void render(sf::RenderWindow &window);
        void move(const float &dt, sf::Vector2f velocity);
        void reset();
        bool startTimer(const float &dt);
};

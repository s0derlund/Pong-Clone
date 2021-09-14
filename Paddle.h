#pragma once

#include <iostream>

#include "Entity.h"

class Paddle : public Entity
{
    private:
        
    public:
        // Constructor / Destructor
        Paddle(sf::Vector2f position, std::string path, bool player);
        virtual ~Paddle();

        // Functions
        void initSprite(std::string path, bool player);
        void collision();
        void update(const float &dt);
        void render(sf::RenderWindow &window);
        void move(const float &dt, sf::Vector2f velocity);
        void reset();
};

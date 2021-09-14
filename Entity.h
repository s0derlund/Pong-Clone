#pragma once

#include "global.h"

#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/**
* 
* 
* Abstract class for classes Ball/Player and Enemy
*/
class Entity
{
    protected:
        // Data members of class
        float movementspeed;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f position;
        sf::Vector2f velocity;

    public:

        virtual void move(const float &dt, sf::Vector2f velocity) = 0;
        virtual void update(const float &dt) = 0;
        virtual void render(sf::RenderWindow &window) = 0;
        virtual void reset() = 0;
        virtual void collision() = 0;
        virtual void setVelocity(sf::Vector2f velocity) { this->velocity = velocity; };
        virtual sf::Vector2f& getVelocity() { return this->velocity; };
        virtual sf::Sprite& getSprite() { return this->sprite; };
        virtual sf::Sprite loadSprite(std::string path) {
        
            this->texture.loadFromFile(path);
            return sf::Sprite(this->texture);
        };
};

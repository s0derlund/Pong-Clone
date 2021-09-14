#pragma once
#include <SFML/Graphics.hpp>
#include "global.h"

class ScoreBoard
{
    private:
        // Varibles
        sf::Vector2i playerScore;
        
        sf::Font scoreFont;
        sf::Text scoreText;

        void initFont();
        void initText();

    public:

        ScoreBoard();
        virtual ~ScoreBoard();

        // Functions
        
        void update(const float &dt);
        void render(sf::RenderWindow &window);
        void reset();
        void setPlayerScore(bool players);


};

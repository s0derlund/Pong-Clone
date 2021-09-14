#include "ScoreBoard.h"

void ScoreBoard::initFont()
{
    this->scoreFont.loadFromFile("assets/Fonts/BalooChettan2-Medium.ttf");
}

void ScoreBoard::initText()
{
    this->scoreText.setFont(this->scoreFont);
    this->scoreText.setString("0 : 0");
    this->scoreText.setCharacterSize(50);
    this->scoreText.setStyle(sf::Text::Bold);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setPosition((constant::GLOBAL_WINDOW_WIDTH / 2) - (this->scoreText.getGlobalBounds().width / 2), 20);
}

ScoreBoard::ScoreBoard()
{
    this->initFont();
    this->initText();
}

ScoreBoard::~ScoreBoard()
{

}

// Functions

void ScoreBoard::setPlayerScore(bool players)
{
    if(players)
        this->playerScore.x = this->playerScore.x + 1;
    else
        this->playerScore.y = this->playerScore.y + 1;
}

void ScoreBoard::update(const float &dt)
{
   this->scoreText.setString(std::to_string(this->playerScore.x) + " : " + std::to_string(this->playerScore.y));
}

void ScoreBoard::render(sf::RenderWindow &window)
{
    window.draw(this->scoreText);
}

void ScoreBoard::reset()
{
    this->playerScore.x = 0;
    this->playerScore.y = 0;
}

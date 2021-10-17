#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>

class Player
{
public:
	Player()
	{
		//Default
	}
	Player(std::string imgDirectory)
	{
		if (!pTexture.loadFromFile(imgDirectory))
		{
			std::cerr << "Error\n";
		}
		pSprite.setTexture(pTexture);
	}

	void drawPlayer(sf::RenderWindow& window)
	{
		window.draw(pSprite);
	}

	void movePlayer(char direction, float moveSpeed)
	{
		if (direction == 'u')
		{
			pSprite.move(0, -moveSpeed);
		}
		else if (direction == 'd')
		{
			pSprite.move(0, moveSpeed);
		}
		else if (direction == 'l')
		{
			pSprite.move(-moveSpeed, 0);
		}
		else if (direction == 'r')
		{
			pSprite.move(moveSpeed, 0);
		}
	}

private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
};


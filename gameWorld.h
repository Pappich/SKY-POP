#pragma once
#include<SFML\Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
public:
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	std::vector <sf::Vector2i> enemyPositions;

	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();

	std::vector< std::vector <GameTile*>> tiles;
	int gridLength;
	GameWorld();
};

#endif
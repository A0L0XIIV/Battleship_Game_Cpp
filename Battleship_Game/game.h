#pragma once
#include "player.h"

class game {
private:
	// Player1
	player Player1;
	// Player2
	player Player2;

public:
	// Constructer
	game();
	// Functions
	void changeShipHealth(bool *ship);
	void checkGameOver();
	// Destroyer
	~game();
};


// One of the players attack the ships
void game::changeShipHealth(bool* ship) {

}
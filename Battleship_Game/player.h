#pragma once
#define horizantalSize 10
#define verticalSize 10

class player {
private:
	// Grid areas - Ships represented as C1,C2,C3,... and D1,D2,D3
	char* playerArea[horizantalSize][verticalSize] = {};
	char* enemyArea[horizantalSize][verticalSize] = {};
	// Player's ships
	bool carrier[5] = { true };		// C1-C2-C3-C4-C5
	bool battleship[4] = { true };	// B1-B2-B3-B4
	bool destroyer[3] = { true };	// D1-D2-D3
	bool submarine[3] = { true };	// S1-S2-S3
	bool corvette[2] = { true };	// O1-O2
	// Player's all ship health - Sink or not
	bool playersShipStatus[5] = { true }; // For win-lose check, true means alive

public:
	// Constructer
	player();
	// Functions
	bool enemyAttack(int x, int y);
	bool didShipSink(bool *ship);
	// Destroyer
	~player();

};

// Gets coordinates as a input, returns true on hit - false on miss
bool player::enemyAttack(int x, int y) {
	char* attackedZone = this->playerArea[x][y];

	// Check player's zone for hit
	if (attackedZone != "") {
		// Hit, check which ship and update ship's health
		switch (attackedZone[0]) {
			// Carrier
			case 'C':
				// Change player's carrier ship health
				this->carrier[attackedZone[1]] = false;
				// Check if the player's carreir sink or not, if sank update playersShipStatus array
				if (this->didShipSink(this->carrier))
					this->playersShipStatus[0] = false;
				break;
			// Battleship
			case 'B':
				// Change player's battleship ship health
				this->battleship[attackedZone[1]] = false;
				// Check if the player's battleship sink or not, if sank update playersShipStatus array
				if (this->didShipSink(this->battleship))
					this->playersShipStatus[1] = false;
				break;
			// Destroyer
			case 'D':
				// Change player's destroyer ship health
				this->destroyer[attackedZone[1]] = false;
				// Check if the player's destroyer sink or not, if sank update playersShipStatus array
				if (this->didShipSink(this->destroyer))
					this->playersShipStatus[2] = false;
				break;
			// Submarine
			case 'S':
				// Change player's submarine ship health
				this->submarine[attackedZone[1]] = false;
				// Check if the player's submarine sink or not, if sank update playersShipStatus array
				if (this->didShipSink(this->submarine))
					this->playersShipStatus[3] = false;
				break;
			// Corvette
			case 'O':
				// Change player's corvette ship health
				this->corvette[attackedZone[1]] = false;
				// Check if the player's corvette sink or not, if sank update playersShipStatus array
				if (this->didShipSink(this->corvette))
					this->playersShipStatus[4] = false;
				break;
			// Default
			default:
				break;
		}
		// Return hit
		return true;
	}

	// Miss, return false
	return false;
}


// Check if the attacked ship sank or not
bool player::didShipSink(bool *ship) {
	// Get ship's health bar - array size
	int shipHealth = (sizeof(ship) / sizeof(*ship));

	// Loop over the ship and return false on not attacked ship area
	for (int i = 0; i < shipHealth; i++) {
		// If the ship's one of the area is not hit by the enemy - return false
		if (ship[i] == true)
			return false;
	}
	// Ship's all area are false - ship sank
	return true;
}
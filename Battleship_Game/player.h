#pragma once
#define horizantalSize 10
#define verticalSize 10

class player {
private:
	// Grid area
	char* playerArea[horizantalSize][verticalSize] = {};
	// Player's ships
	bool carrier[5] = { true };
	bool battleship[4] = { true };
	bool destroyer[3] = { true };
	bool submarine[3] = { true };
	bool corvette[2] = { true };
	// Player's all ship health
	bool isShipAlive[5] = { true };

public:
	// Constructer
	player();
	// Functions
	bool enemyAttack(int x, int y);
	bool isShipAlive(int shipNumber);
	// Destroyer
	~player();

};

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
				break;
			// Battleship
			case 'B':
				// Change player's battleship ship health
				this->battleship[attackedZone[1]] = false;
				break;
			// Destroyer
			case 'D':
				// Change player's destroyer ship health
				this->destroyer[attackedZone[1]] = false;
				break;
			// Submarine
			case 'S':
				// Change player's submarine ship health
				this->submarine[attackedZone[1]] = false;
				break;
			// Corvette
			case 'O':
				// Change player's corvette ship health
				this->corvette[attackedZone[1]] = false;
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

bool player::isShipAlive(int shipNumber) {
	// Ship array and its health counter
	bool *ship;
	int shipHealth = 0;

	// Get ship's array with given shipNumber. 0->carrier, 1->battleship,...
	switch (shipNumber) {
		case 0:
			ship = this->carrier;
			break;
		case 1:
			ship = this->battleship;
			break;
		case 2:
			ship = this->destroyer;
			break;
		case 3:
			ship = this->submarine;
			break;
		case 4:
			ship = this->corvette;
			break;
		default:
			break;
	}

	// Get ship array's size as a health bar
	shipHealth = ship.size();

	// Check given ship's all parts for true
	while (ship) {
		// Decrease ship's health
		shipHealth--;
		// Traverse in ship array
		ship++;
	}

	// Return true if ship has still health
	if (shipHealth > 0)
		return true;
	else
		return false;
}
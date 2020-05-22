#include "checkGameOver.h"

void check_carring(vector < vector <char> >& map, position dummy, position host_position, bool &carring) {
	for (int i = host_position.y - 1; i < host_position.y + 1; i++) {
		for (int j = host_position.x - 1; j < host_position.x + 1; j++) {
			if (dummy.x == j and dummy.y == i) {
				cout << "document's been saved" << endl;
				carring = true;
			}
		}
	}
	return;
}

bool check_game(vector < vector <char> >& map, position dummy, bool &carring, Clock gameTime) {
	//position position_host = checkNearestHost(host_position, dummy_position);
	if (map[dummy.y][dummy.x] == '9' and carring == true) {
		return true;
	}
	if (gameTime.getElapsedTime().asSeconds() > 120.0f) {
		cout << "The hostage dided!";
		return true;
	}
	return false;
}

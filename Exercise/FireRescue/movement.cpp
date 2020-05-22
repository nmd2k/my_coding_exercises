#include "movement.h"


void movement(Event event, vector < vector <char> >& map, position& dummy_position) {
	int x = dummy_position.x;
	int y = dummy_position.y;
	switch (event.key.code)
	{
	case Keyboard::Up:
		cout << "up-key pressed" << endl;
		if ((map[y - 1][x] == '0' or map[y - 1][x] == '5') and y - 1 >= 0) {
			y--;
		}
		if (map[y - 1][x] == '3' and map[y - 2][x] == '0' and y - 2 >= 0) { //out of the map
			map[y - 1][x] = '0';
			map[y - 2][x] = '3';
			y--;
		}
		break;
	case Keyboard::Down:
		cout << "down-key pressed" << endl;
		if ((map[y + 1][x] == '0' or map[y + 1][x] == '5') and y + 1 <= map_height) {
			y++;
		}
		if (map[y + 1][x] == '3' and map[y + 2][x] == '0' and y + 2 <= map_height) {
			map[y + 1][x] = '0';
			map[y + 2][x] = '3';
			y++;
		}
		break;
	case Keyboard::Left:
		cout << "left-key pressed" << endl;
		if ((map[y][x - 1] == '0' or map[y][x - 1] == '5') and x - 1 >= 0) {
			x--;
		}
		if (map[y][x - 1] == '3' and map[y][x - 2] == '0' and x - 2 >= 0) {
			map[y][x - 1] = '0';
			map[y][x - 2] = '3';
			x--;
		}
		break;
	case Keyboard::Right:
		cout << "right-key pressed" << endl;
		if ((map[y][x + 1] == '0' or map[y][x + 1] == '5') and x + 1 <= map_width) {
			x++;
		}
		if (map[y][x + 1] == '3' and map[y][x + 2] == '0' and x + 2 <= map_width) {
			map[y][x + 1] = '0';
			map[y][x + 2] = '3';
			x++;
		}
		break;
	default:
		break;
	}
}
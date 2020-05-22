#include "setPosition.h"

void setPosition(vector < vector <char> >& map, position& dummy_position, position& host_position) { //vector <position>& host_position
	ifor(i, map_height) {
		ifor(j, map_width) {
			if (map[i][j] == '7') {
				//generate dummy's position
				dummy_position.x = j;
				dummy_position.y = i;
				map[i][j] = '0';
			}
			else if (map[i][j] == '8') {
				//generate hostages's position
				host_position.x = j;
				host_position.y = i;
				map[i][j] = '0';
			}
		}
	}
}
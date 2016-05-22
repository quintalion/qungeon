#include <iostream>
#include "qungeon/Room.h"
#include "qungeon/stream_player.h"

int main() {
	qungeon::room start("You are in a very dark hole with no exits.  Yay?");
	qungeon::stream_player player(std::cin, std::cout, start);

	std::cout << "Welcome to Qungeon." << std::endl;
	
	while (player.is_alive())
	{
		player.process_command();
	}
	std::cout << "Exiting qungeon." << std::endl;
	system("pause");
	return 0;
}
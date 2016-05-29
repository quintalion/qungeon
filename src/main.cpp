#include <iostream>
#include "qungeon/default_room.h"
#include "qungeon/default_actor.h"
#include "qungeon/stream_player.h"

int main() {
	qungeon::default_room start("You are in a very dark hole with no exits.  Yay?");
	qungeon::default_actor actor(&start);
	qungeon::stream_player player(std::cin, std::cout, &actor);

	std::cout << "Welcome to Qungeon." << std::endl;
	
	while (player.is_alive())
	{
		player.process_command();
	}
	std::cout << "Exiting qungeon." << std::endl;
	system("pause");
	return 0;
}
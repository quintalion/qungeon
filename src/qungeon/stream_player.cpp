#include "stream_player.h"

namespace qungeon
{

stream_player::stream_player(std::istream &input, std::ostream &output, qungeon::room start_room)
	: input{ input }, output{ output }, current_room{ start_room }
{

}

bool stream_player::is_alive() const
{
	return alive;
}

void stream_player::quit()
{
	alive = false;
}

void stream_player::process_command()
{
	output << "What would you like to do?" << std::endl;
	const size_t buffer_size = 255;
	char input_buffer[buffer_size];

	input.getline(input_buffer, buffer_size);
	std::string command = input_buffer;
	for (auto &c : command)
	{
		c = ::toupper(c);
	}

	if (command == "QUIT")
	{
		alive = false;
	}
	else if (command == "LOOK")
	{
		current_room.look(output);
	}
}

}

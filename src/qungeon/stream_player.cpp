#include "stream_player.h"
#include "actor.h"

namespace qungeon
{

stream_player::stream_player(std::istream &input, std::ostream &output, qungeon::actor* actor)
	: input{ input }, output{ output }, actor{ actor }
{

}

bool stream_player::is_alive() const
{
	return actor->is_alive();
}

void stream_player::quit()
{
	actor->quit();
}

void stream_player::process_command()
{
	const char *CAN_NOT_MOVE = "You can not move that way";

	output << "> " << std::flush;
	const size_t buffer_size = 255;
	char input_buffer[buffer_size];

	input.getline(input_buffer, buffer_size);
	std::string command = input_buffer;
	for (auto &c : command)
	{
		c = ::toupper(c);
	}

	// FIXME: hit with refactor bat
	if (command == "QUIT")
	{
		actor->quit();
	}
	else if (command == "LOOK")
	{
		actor->look(output);
	}
	else if (command == "NORTH")
	{
		if (actor->can_move_north()) {
			actor->north();
			actor->look(output);
		}
		else
		{
			output << CAN_NOT_MOVE << std::endl;
		}
	}
	else if (command == "SOUTH")
	{
		if (actor->can_move_south()) {
			actor->south();
			actor->look(output);
		}
		else
		{
			output << CAN_NOT_MOVE << std::endl;
		}
	}
	else if (command == "EAST")
	{
		if (actor->can_move_east()) {
			actor->east();
			actor->look(output);
		}
		else
		{
			output << CAN_NOT_MOVE << std::endl;
		}
	}
	else if (command == "WEST")
	{
		if (actor->can_move_west()) {
			actor->west();
			actor->look(output);
		}
		else
		{
			output << CAN_NOT_MOVE << std::endl;
		}
	}
}

}

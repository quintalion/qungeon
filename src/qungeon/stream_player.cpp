#include "stream_player.h"

#include <memory>

#include "actor.h"
#include "command/command.h"
#include "command/quit_command.h"
#include "command/look_command.h"
#include "command/north_command.h"
#include "command/south_command.h"
#include "command/east_command.h"
#include "command/west_command.h"
#include "command/unknown_command.h"

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
	std::string input_command = input_buffer;
	for (auto &c : input_command)
	{
		c = ::toupper(c);
	}

	// FIXME: hit with refactor bat
	std::unique_ptr<qungeon::command::command> command;
	if (input_command == "QUIT")
	{
		command = std::make_unique<qungeon::command::quit_command>(actor);
	}
	else if (input_command == "LOOK")
	{
		command = std::make_unique<qungeon::command::look_command>(actor, &output);
	}
	else if (input_command == "NORTH")
	{
		command = std::make_unique<qungeon::command::north_command>(actor, &output);
	}
	else if (input_command == "SOUTH")
	{
		command = std::make_unique<qungeon::command::south_command>(actor, &output);
	}
	else if (input_command == "EAST")
	{
		command = std::make_unique<qungeon::command::east_command>(actor, &output);
	}
	else if (input_command == "WEST")
	{
		command = std::make_unique<qungeon::command::west_command>(actor, &output);
	}
	else {
		command = std::make_unique<qungeon::command::unknown_command>(&output);
	}

	command->execute();
}

}

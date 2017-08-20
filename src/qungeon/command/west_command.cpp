#include "west_command.h"
#include "../actor.h"

namespace qungeon
{

namespace command
{

west_command::west_command(qungeon::actor* actor, std::ostream* output)
	: move_command{ actor, output }
{}

bool west_command::can_move()
{
	return actor->can_move_west();
}

void west_command::move()
{
	return actor->west();
}

}

}

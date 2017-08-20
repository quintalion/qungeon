#include "south_command.h"
#include "../actor.h"

namespace qungeon
{

namespace command
{

south_command::south_command(qungeon::actor* actor, std::ostream* output)
	: move_command{ actor, output }
{}

bool south_command::can_move()
{
	return actor->can_move_south();
}

void south_command::move()
{
	return actor->south();
}

}

}

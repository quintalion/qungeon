#include "east_command.h"
#include "../actor.h"

namespace qungeon
{

namespace command
{

east_command::east_command(qungeon::actor* actor, std::ostream* output)
	: move_command{ actor, output }
{}

bool east_command::can_move()
{
	return actor->can_move_east();
}

void east_command::move()
{
	return actor->east();
}

}

}

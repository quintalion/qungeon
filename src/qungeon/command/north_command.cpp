#include "north_command.h"
#include "../actor.h"

namespace qungeon
{

namespace command
{

north_command::north_command(qungeon::actor* actor, std::ostream* output)
	: move_command{ actor, output }
{}

bool north_command::can_move()
{
	return actor->can_move_north();
}

void north_command::move()
{
	return actor->north();
}


}

}

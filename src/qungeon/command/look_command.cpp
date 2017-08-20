#include "look_command.h"
#include "../actor.h"

namespace qungeon
{

namespace command
{

look_command::look_command(qungeon::actor* actor, std::ostream* output)
	: actor{ actor }, output{ output }
{}

void look_command::execute()
{
	actor->look(*output);
}

}

}

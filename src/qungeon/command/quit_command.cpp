#include "quit_command.h"
#include "../actor.h"

namespace qungeon
{

namespace command
{

quit_command::quit_command(qungeon::actor* actor)
	: actor { actor }
{

}

void quit_command::execute()
{
	actor->quit();
}

}

}

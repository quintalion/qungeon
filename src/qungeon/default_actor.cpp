#include "default_actor.h"
#include "room.h"

namespace qungeon
{

default_actor::default_actor(room* start_room)
	: current_room(start_room)
{

}

bool default_actor::is_alive() const
{
	return alive;
}

void default_actor::quit()
{
	alive = false;
}

void default_actor::look(std::ostream& output) const
{
	current_room->write_description(output);
}

}

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

bool default_actor::can_move_north() const
{
	return current_room->has_north_exit();
}

bool default_actor::can_move_south() const
{
	return current_room->has_south_exit();
}

bool default_actor::can_move_east() const
{
	return current_room->has_east_exit();
}

bool default_actor::can_move_west() const
{
	return current_room->has_west_exit();
}

void default_actor::set_location(qungeon::room* room)
{
	current_room = room;
}

void default_actor::quit()
{
	alive = false;
}

void default_actor::look(std::ostream& output) const
{
	current_room->write_description(output);
}

void default_actor::north()
{
	current_room->transit_north(this);
}

void default_actor::south()
{
	current_room->transit_south(this);
}

void default_actor::east()
{
	current_room->transit_east(this);
}

void default_actor::west()
{
	current_room->transit_west(this);
}

}

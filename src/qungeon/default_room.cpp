#include "default_room.h"

#include "movable.h"
#include "illegal_move_exception.h"

namespace qungeon
{

default_room::default_room(const std::string &description)
	: description{ description }
{}

void default_room::set_north(qungeon::room* room)
{
	north_room = room;
}

void default_room::set_south(qungeon::room* room)
{
	south_room = room;
}

void default_room::set_east(qungeon::room* room)
{
	east_room = room;
}

void default_room::set_west(qungeon::room* room)
{
	west_room = room;
}

bool default_room::has_north_exit() const
{
	return north_room != nullptr;
}

bool default_room::has_south_exit() const
{
	return south_room != nullptr;
}

bool default_room::has_east_exit() const
{
	return east_room != nullptr;
}

bool default_room::has_west_exit() const
{
	return west_room != nullptr;
}

void default_room::transit_to(qungeon::movable* movable, qungeon::room* room, const char* exception_what) const
{
	if (room != nullptr)
	{
		movable->set_location(room);
	}
	else
	{
		throw qungeon::illegal_move_exception(exception_what);
	}
}

void default_room::transit_north(qungeon::movable* movable_object) const
{
	transit_to(movable_object, north_room, "No north room");
}

void default_room::transit_south(qungeon::movable* movable_object) const
{
	transit_to(movable_object, south_room, "No south room");
}

void default_room::transit_east(qungeon::movable* movable_object) const
{
	transit_to(movable_object, east_room, "No east room");
}

void default_room::transit_west(qungeon::movable* movable_object) const
{
	transit_to(movable_object, west_room, "No west room");
}

void default_room::write_description(std::ostream &output) const
{
	output << description << std::endl;
}

}

#include "default_room.h"

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

qungeon::room* default_room::get_north() const
{
	return north_room;
}

qungeon::room* default_room::get_south() const
{
	return south_room;
}

qungeon::room* default_room::get_east() const
{
	return east_room;
}

qungeon::room* default_room::get_west() const
{
	return west_room;
}

void default_room::write_description(std::ostream &output) const
{
	output << description << std::endl;
}

}

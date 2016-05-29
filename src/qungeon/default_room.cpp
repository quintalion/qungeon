#include "default_room.h"

namespace qungeon
{

default_room::default_room(const std::string &description)
	: description{ description }
{}

void default_room::write_description(std::ostream &output) const
{
	output << description << std::endl;
}

}

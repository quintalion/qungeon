#include "room.h"

namespace qungeon
{

room::room(const std::string &description)
	: description{ description }
{}

void room::look(std::ostream &output)
{
	output << description << std::endl;
}

}

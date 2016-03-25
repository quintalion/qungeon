#include "room.h"

namespace qungeon
{

room::room(const std::string &description)
	: description{ description }
{}

void room::look(input_output &io)
{
	io.write_line(description);
}

}

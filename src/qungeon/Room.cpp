#include "Room.h"

namespace qungeon
{

Room::Room(const std::string &description)
	: _description(description)
{}

void Room::look(InputOutput &io)
{
	io.WriteLine(_description);
}

}

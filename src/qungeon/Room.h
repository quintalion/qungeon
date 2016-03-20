#pragma once

#include "InputOutput.h"
#include <string>

namespace qungeon
{

class Room
{
public:
	explicit Room(const std::string &description);

	void look(InputOutput &io);

private:
	std::string _description;
};

}

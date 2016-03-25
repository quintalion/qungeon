#pragma once

#include "input_output.h"
#include <string>

namespace qungeon
{

class room
{
public:
	explicit room(const std::string &description);

	void look(input_output &io);

private:
	std::string description;
};

}

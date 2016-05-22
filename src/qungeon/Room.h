#pragma once

#include <ostream>
#include <string>

namespace qungeon
{

class room
{
public:
	explicit room(const std::string &description);

	void look(std::ostream &output);

private:
	std::string description;
};

}

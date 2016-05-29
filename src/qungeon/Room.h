#pragma once

#include <ostream>

namespace qungeon
{

class room
{
public:
	virtual ~room() = default;

	virtual void write_description(std::ostream &output) const = 0;
};

}

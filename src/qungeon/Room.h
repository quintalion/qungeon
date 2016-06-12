#pragma once

#include <ostream>

namespace qungeon
{

class room
{
public:
	virtual ~room() = default;

	virtual void write_description(std::ostream &output) const = 0;
	virtual qungeon::room* get_north() const = 0;
	virtual qungeon::room* get_south() const = 0;
	virtual qungeon::room* get_east() const = 0;
	virtual qungeon::room* get_west() const = 0;
};

}

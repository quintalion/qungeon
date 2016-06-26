#pragma once

#include <ostream>

namespace qungeon
{

class movable;

class room
{
public:
	virtual ~room() = default;

	virtual void write_description(std::ostream &output) const = 0;
	virtual void transit_north(qungeon::movable* movable) const = 0;
	virtual void transit_south(qungeon::movable* movable) const = 0;
	virtual void transit_east(qungeon::movable* movable) const = 0;
	virtual void transit_west(qungeon::movable* movable) const = 0;
};

}

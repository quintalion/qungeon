#pragma once

#include <ostream>

namespace qungeon
{

class movable;

class room
{
public:
	virtual ~room() = default;

	virtual bool has_north_exit() const = 0;
	virtual bool has_south_exit() const = 0;
	virtual bool has_east_exit() const = 0;
	virtual bool has_west_exit() const = 0;

	virtual void write_description(std::ostream &output) const = 0;
	virtual void transit_north(qungeon::movable* movable) const = 0;
	virtual void transit_south(qungeon::movable* movable) const = 0;
	virtual void transit_east(qungeon::movable* movable) const = 0;
	virtual void transit_west(qungeon::movable* movable) const = 0;
};

}

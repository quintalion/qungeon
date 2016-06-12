#pragma once

#include <ostream>

namespace qungeon
{

class default_room;

class actor
{
public:
	virtual ~actor() = default;
	virtual bool is_alive() const = 0;

	virtual void quit() = 0;
	virtual void look(std::ostream& output) const = 0;
	virtual void north() = 0;
};

}

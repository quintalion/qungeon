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
	virtual bool can_move_north() const = 0;
	virtual bool can_move_south() const = 0;
	virtual bool can_move_east() const = 0;
	virtual bool can_move_west() const = 0;

	virtual void quit() = 0;
	virtual void look(std::ostream& output) const = 0;
	virtual void north() = 0;
	virtual void south() = 0;
	virtual void east() = 0;
	virtual void west() = 0;
};

}

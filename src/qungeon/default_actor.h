#pragma once

#include "actor.h"

namespace qungeon
{

class room;

class default_actor : public actor
{
public:
	explicit default_actor(room* start_room);
	bool is_alive() const override;

	void quit() override;
	void look(std::ostream& output) const override;
	void north() override;

private:
	bool alive = true;
	room* current_room;
};

}

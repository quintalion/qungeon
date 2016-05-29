#pragma once

#include "actor.h"

namespace qungeon
{

class room;

class default_actor : public actor
{
public:
	explicit default_actor(room* start_room);
	virtual bool is_alive() const override;

	virtual void quit() override;
	virtual void look(std::ostream& output) const override;

private:
	bool alive = true;
	room* current_room;
};

}

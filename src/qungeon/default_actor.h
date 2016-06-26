#pragma once

#include "actor.h"
#include "movable.h"

namespace qungeon
{

class room;

class default_actor : public actor, public movable
{
public:
	explicit default_actor(room* start_room);
	bool is_alive() const override;

	void set_location(qungeon::room* room) override;

	void quit() override;
	void look(std::ostream& output) const override;
	void north() override;
	void south() override;
	void east() override;
	void west() override;

private:
	bool alive = true;
	room* current_room;
};

}

#pragma once

#include <ostream>

#include "move_command.h"

namespace qungeon
{

class actor;

namespace command
{

class west_command : public move_command
{
public:
	west_command(qungeon::actor* actor, std::ostream* output);
	~west_command() override = default;

protected:
	bool can_move() override;
	void move() override;

};

}

}


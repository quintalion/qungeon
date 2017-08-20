#pragma once

#include <ostream>

#include "move_command.h"

namespace qungeon
{

class actor;

namespace command
{

class east_command : public move_command
{
public:
	east_command(qungeon::actor* actor, std::ostream* output);
	~east_command() override = default;

protected:
	bool can_move() override;
	void move() override;

};

}

}


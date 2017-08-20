#pragma once

#include <ostream>

#include "move_command.h"

namespace qungeon
{

class actor;

namespace command
{

class south_command : public move_command
{
public:
	south_command(qungeon::actor* actor, std::ostream* output);
	~south_command() override = default;

protected:
	bool can_move() override;
	void move() override;
};

}

}
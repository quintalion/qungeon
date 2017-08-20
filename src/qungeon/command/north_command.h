#pragma once

#include <ostream>

#include "move_command.h"

namespace qungeon
{

class actor;

namespace command
{

class north_command : public move_command
{
public:
	north_command(qungeon::actor* actor, std::ostream* output);
	~north_command() override = default;

protected:
	bool can_move() override;
	void move() override;
	
};


}

}

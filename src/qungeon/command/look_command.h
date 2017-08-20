#pragma once

#include "command.h"
#include <ostream>

namespace qungeon
{

class actor;

namespace command
{

class look_command : public command
{
public:
	look_command(qungeon::actor* actor, std::ostream* output);
	~look_command() override = default;

	void execute() override;

private:
	qungeon::actor* actor;
	std::ostream* output;
};

}

}

#pragma once

#include <ostream>

#include "command.h"

namespace qungeon
{

namespace command
{

class unknown_command : public command
{
public:
	unknown_command(std::ostream* output);
	virtual ~unknown_command() = default;

	void execute() override;

private:
	std::ostream* output;
};

}

}

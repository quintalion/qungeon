#pragma once

#include "command.h"

namespace qungeon
{

class actor;

namespace command
{

class quit_command : public command
{
public:
	quit_command(qungeon::actor* actor);
	~quit_command() override = default;

	void execute() override;

private:
	actor* actor;
};

}

}
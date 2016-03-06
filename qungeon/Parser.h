#pragma once

#include "InputOutput.h"

namespace qungeon
{

class Parser
{
public:
	explicit Parser(InputOutput&);
	Parser(Parser&) = delete;

	Parser& operator=(Parser&) = delete;

	std::string GetCommand();

private:
	static const size_t COMMAND_LENGTH = 3;

	InputOutput &_io;
};

}

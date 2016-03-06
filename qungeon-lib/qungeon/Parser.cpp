#include "Parser.h"

namespace qungeon
{

Parser::Parser(InputOutput &io)
	: _io(io)
{

}

std::string Parser::GetCommand()
{
	return _io.ReadLine().substr(0, COMMAND_LENGTH);
}

}

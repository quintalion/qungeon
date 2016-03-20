#include "Parser.h"

namespace qungeon
{

Parser::Parser(InputOutput &io)
	: _io(io)
{

}

std::string Parser::GetCommand()
{
	std::string rawString = _io.ReadLine().substr(0, COMMAND_LENGTH);
	for (auto &c : rawString)
	{
		c = ::toupper(c); 
	}
	return rawString;
}

}

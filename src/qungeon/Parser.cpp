#include "Parser.h"

namespace qungeon
{

parser::parser(input_output &io)
: io{ io }
{

}

std::string parser::get_command()
{
	std::string raw_string = io.read_line().substr(0, command_length);
	for (auto &c : raw_string)
	{
		c = ::toupper(c); 
	}
	return raw_string;
}

}

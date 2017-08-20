#include "unknown_command.h"

namespace qungeon
{

namespace command
{

unknown_command::unknown_command(std::ostream* output)
	: output{ output }
{
}
	
void unknown_command::execute()
{
	*output << "Unknown command" << std::endl;
}

}

}
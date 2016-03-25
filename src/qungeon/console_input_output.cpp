#include "console_input_output.h"

#include <iostream>

namespace qungeon
{

void console_input_output::write_line(const std::string &message)
{
	std::cout << message << std::endl;
}

std::string console_input_output::read_line()
{
	std::cin.getline(input_buffer, buffer_size);
	return input_buffer;
}

}

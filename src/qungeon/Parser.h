#pragma once

#include "input_output.h"

namespace qungeon
{

class parser
{
public:
	explicit parser(input_output&);
	parser(const parser &) = delete;
	parser(parser &&) = delete;

	parser &operator=(const parser &) = delete;
	parser &operator=(parser &&) = delete;

	std::string get_command();

private:
	static constexpr size_t command_length = 3;

	input_output &io;
};

}

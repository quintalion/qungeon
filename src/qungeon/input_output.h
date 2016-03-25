#pragma once

#include <string>

namespace qungeon
{

/*
Interface for various kinds of Input and Output from a player.
*/
class input_output
{
public:
	input_output() = default;
	input_output(const input_output &) = delete;
	input_output(input_output &&) = delete;
	virtual ~input_output() = default;

	input_output &operator=(const input_output &) = delete;
	input_output &operator=(input_output &&) = delete;

	virtual void write_line(const std::string &) = 0;
	virtual std::string read_line() = 0;
};

}

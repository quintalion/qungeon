#pragma once

#include <string>

namespace qungeon
{

/*
Interface for various kinds of Input and Output from a player.
*/
class InputOutput
{
public:
	InputOutput() = default;
	InputOutput(const InputOutput &) = delete;
	InputOutput(InputOutput &&) = delete;
	virtual ~InputOutput() = default;

	InputOutput &operator=(const InputOutput &) = delete;
	InputOutput &operator=(InputOutput &&) = delete;

	virtual void WriteLine(const std::string &) = 0;
	virtual std::string ReadLine() = 0;
};

}

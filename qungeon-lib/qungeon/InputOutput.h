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
	virtual void WriteLine(const std::string &) = 0;
	virtual std::string ReadLine() = 0;
};

}

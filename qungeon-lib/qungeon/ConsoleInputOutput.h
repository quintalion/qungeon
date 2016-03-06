#pragma once

#include "InputOutput.h"

namespace qungeon
{

/*
Boundary class for simple console input and output
*/
class ConsoleInputOutput : public InputOutput
{
public:
	ConsoleInputOutput() = default;
	ConsoleInputOutput(ConsoleInputOutput&) = delete;

	ConsoleInputOutput& operator=(ConsoleInputOutput&) = delete;

	virtual void WriteLine(const std::string &);
	virtual std::string ReadLine();

private:
	static const size_t BUFFER_SIZE = 255;

	char _inputBuffer[BUFFER_SIZE];
};

}

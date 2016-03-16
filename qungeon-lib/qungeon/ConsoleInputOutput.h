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
	ConsoleInputOutput(const ConsoleInputOutput &) = delete;
	ConsoleInputOutput(ConsoleInputOutput &&) = delete;

	ConsoleInputOutput& operator=(const ConsoleInputOutput &) = delete;
	ConsoleInputOutput& operator=(ConsoleInputOutput &&) = delete;

	void WriteLine(const std::string &) override;
	std::string ReadLine() override;

private:
	static const size_t BUFFER_SIZE = 255;

	char _inputBuffer[BUFFER_SIZE];
};

}

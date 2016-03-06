#include "ConsoleInputOutput.h"

#include <iostream>

namespace qungeon
{

void ConsoleInputOutput::WriteLine(const std::string &message)
{
	std::cout << message << std::endl;
}

std::string ConsoleInputOutput::ReadLine()
{
	std::cin.getline(_inputBuffer, BUFFER_SIZE);
	return _inputBuffer;
}

}

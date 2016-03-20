#include "qungeon/ConsoleInputOutput.h"
#include "qungeon/Parser.h"

void main() {
	qungeon::ConsoleInputOutput io;
	qungeon::Parser parser(io);

	io.WriteLine("Welcome to Qungeon.");
	std::string command;
	do
	{
		io.WriteLine("What would you like to do?");
		command = parser.GetCommand();
	} while (command != "QUI");

	io.WriteLine("Exiting qungeon.");
	system("pause");
}
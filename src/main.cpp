#include "qungeon/ConsoleInputOutput.h"
#include "qungeon/Parser.h"
#include "qungeon/Room.h"

void main() {
	qungeon::ConsoleInputOutput io;
	qungeon::Parser parser(io);
	qungeon::Room start("You are in a very dark hole with no exits.  Yay?");

	io.WriteLine("Welcome to Qungeon.");
	std::string command;
	do
	{
		io.WriteLine("What would you like to do?");
		command = parser.GetCommand();

		if (command == "LOO")
		{
			start.look(io);
		}
	} while (command != "QUI");

	io.WriteLine("Exiting qungeon.");
	system("pause");
}
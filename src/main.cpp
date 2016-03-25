#include "qungeon/console_input_output.h"
#include "qungeon/parser.h"
#include "qungeon/Room.h"

int main() {
	qungeon::console_input_output io;
	qungeon::parser parser(io);
	qungeon::room start("You are in a very dark hole with no exits.  Yay?");

	io.write_line("Welcome to Qungeon.");
	std::string command;
	do
	{
		io.write_line("What would you like to do?");
		command = parser.get_command();

		if (command == "LOO")
		{
			start.look(io);
		}
	} while (command != "QUI");

	io.write_line("Exiting qungeon.");
	system("pause");
	return 0;
}
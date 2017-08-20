#pragma once

class command_factory
{
public:
	static command_factory* instance();

private:
	command_factory() = default;

	static command_factory* the_instance;
	
};

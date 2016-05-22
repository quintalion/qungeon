#pragma once

namespace qungeon
{

class player
{
public:
	virtual bool is_alive() const = 0;

	virtual void quit() = 0;
	virtual void process_command() = 0;
};

}

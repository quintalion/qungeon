#pragma once

namespace qungeon
{

namespace command
{

class command
{
public:
	virtual ~command() = default;

	virtual void execute() = 0;
};

}

}

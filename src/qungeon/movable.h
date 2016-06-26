#pragma once

namespace qungeon
{

class room;

class movable
{
public:
	virtual ~movable() = default;

	virtual void set_location(qungeon::room* room) = 0;
};

}

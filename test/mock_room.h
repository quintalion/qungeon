#pragma once

#include "qungeon/room.h"
#include <gmock/gmock.h>

namespace qungeon
{

namespace test
{

class mock_room : public room
{
public:
	MOCK_CONST_METHOD0(has_north_exit, bool());
	MOCK_CONST_METHOD0(has_south_exit, bool());
	MOCK_CONST_METHOD0(has_east_exit, bool());
	MOCK_CONST_METHOD0(has_west_exit, bool());
	MOCK_CONST_METHOD1(write_description, void(std::ostream &output));
	MOCK_CONST_METHOD1(transit_north, void(qungeon::movable* movable));
	MOCK_CONST_METHOD1(transit_south, void(qungeon::movable* movable));
	MOCK_CONST_METHOD1(transit_east, void(qungeon::movable* movable));
	MOCK_CONST_METHOD1(transit_west, void(qungeon::movable* movable));
};

}

}

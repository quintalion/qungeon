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
	MOCK_CONST_METHOD1(write_description, void(std::ostream &output));
	MOCK_CONST_METHOD0(get_north, qungeon::room*());
	MOCK_CONST_METHOD0(get_south, qungeon::room*());
	MOCK_CONST_METHOD0(get_east, qungeon::room*());
	MOCK_CONST_METHOD0(get_west, qungeon::room*());
};

}

}

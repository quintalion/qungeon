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
};

}

}

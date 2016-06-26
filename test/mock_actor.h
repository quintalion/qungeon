#pragma once

#include "qungeon/actor.h"
#include <gmock/gmock.h>

namespace qungeon
{

namespace test
{

class mock_actor : public actor
{
public:
	MOCK_CONST_METHOD0(is_alive, bool());
	MOCK_METHOD0(quit, void());
	MOCK_CONST_METHOD1(look, void(std::ostream& output));
	MOCK_METHOD0(north, void());
	MOCK_METHOD0(south, void());
	MOCK_METHOD0(east, void());
	MOCK_METHOD0(west, void());
};

}

}

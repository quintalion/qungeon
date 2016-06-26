#pragma once

#include "qungeon/movable.h"
#include <gmock/gmock.h>

namespace qungeon
{

namespace test
{

class mock_movable : public qungeon::movable
{
public:
	MOCK_METHOD1(set_location, void(qungeon::room* room));
};

}

}

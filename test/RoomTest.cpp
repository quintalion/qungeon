#include "MockInputOutput.h"
#include "qungeon/Room.h"
#include <gtest/gtest.h>

TEST(RoomTest, lookOutput)
{
	const char *description = "Here is a description";
	qungeon::testing::MockInputOutput mockIo;

	EXPECT_CALL(mockIo, WriteLine(description))
		.Times(1);

	qungeon::Room room(description);

	room.look(mockIo);
}
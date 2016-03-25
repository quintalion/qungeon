#include "mock_input_output.h"
#include "qungeon/room.h"
#include <gtest/gtest.h>

TEST(RoomTest, lookOutput)
{
	const char *description = "Here is a description";
	qungeon::testing::mock_input_output mock_io;

	EXPECT_CALL(mock_io, write_line(description))
		.Times(1);

	qungeon::room room(description);

	room.look(mock_io);
}
#include "qungeon/room.h"
#include <gtest/gtest.h>

TEST(RoomTest, lookOutput)
{
	const std::string description = "Here is a description";
	std::ostringstream output;
	qungeon::room room(description);

	room.look(output);
	EXPECT_EQ(description + '\n', output.str());
}
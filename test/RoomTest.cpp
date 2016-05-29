#include "qungeon/default_room.h"
#include <gtest/gtest.h>

TEST(RoomTest, lookOutput)
{
	const std::string description = "Here is a description";
	std::ostringstream output;
	qungeon::default_room default_room(description);

	default_room.write_description(output);
	EXPECT_EQ(description + '\n', output.str());
}
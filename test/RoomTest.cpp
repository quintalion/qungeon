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

TEST(RoomTest, northRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room north_room(description);

	default_room.set_north(&north_room);
	EXPECT_EQ(&north_room, default_room.get_north());
}

TEST(RoomTest, southRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room south_room(description);

	default_room.set_south(&south_room);
	EXPECT_EQ(&south_room, default_room.get_south());
}

TEST(RoomTest, eastRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room east_room(description);

	default_room.set_east(&east_room);
	EXPECT_EQ(&east_room, default_room.get_east());
}

TEST(RoomTest, westRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room west_room(description);

	default_room.set_west(&west_room);
	EXPECT_EQ(&west_room, default_room.get_west());
}

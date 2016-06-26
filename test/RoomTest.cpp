#include "qungeon/default_room.h"
#include "qungeon/illegal_move_exception.h"
#include "mock_movable.h"
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
	qungeon::test::mock_movable movable_object;

	default_room.set_north(&north_room);
	EXPECT_CALL(movable_object, set_location(&north_room))
		.Times(1);

	default_room.transit_north(&movable_object);
}

TEST(RoomTest, southRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room south_room(description);
	qungeon::test::mock_movable movable_object;

	default_room.set_south(&south_room);
	EXPECT_CALL(movable_object, set_location(&south_room))
		.Times(1);

	default_room.transit_south(&movable_object);
}

TEST(RoomTest, eastRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room east_room(description);
	qungeon::test::mock_movable movable_object;

	default_room.set_east(&east_room);
	EXPECT_CALL(movable_object, set_location(&east_room))
		.Times(1);

	default_room.transit_east(&movable_object);
}

TEST(RoomTest, westRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::default_room west_room(description);
	qungeon::test::mock_movable movable_object;

	default_room.set_west(&west_room);
	EXPECT_CALL(movable_object, set_location(&west_room))
		.Times(1);

	default_room.transit_west(&movable_object);
}

TEST(RoomTest, northWithNoRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::test::mock_movable movable_object;

	EXPECT_THROW(default_room.transit_north(&movable_object), qungeon::illegal_move_exception);
}

TEST(RoomTest, southWithNoRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::test::mock_movable movable_object;

	EXPECT_THROW(default_room.transit_south(&movable_object), qungeon::illegal_move_exception);
}

TEST(RoomTest, eastWithNoRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::test::mock_movable movable_object;

	EXPECT_THROW(default_room.transit_east(&movable_object), qungeon::illegal_move_exception);
}

TEST(RoomTest, westWithNoRoom)
{
	const std::string description = "Here is a description";
	qungeon::default_room default_room(description);
	qungeon::test::mock_movable movable_object;

	EXPECT_THROW(default_room.transit_west(&movable_object), qungeon::illegal_move_exception);
}


#include <iostream>
#include <gtest/gtest.h>
#include "mock_actor.h"
#include "qungeon/stream_player.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::Ref;

TEST(StreamPlayerTest, newPlayerIsAlive)
{
	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, is_alive())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));

	qungeon::stream_player player(std::cin, std::cout, &actor);

	EXPECT_TRUE(player.is_alive());
}

TEST(StreamPlayerTest, quittingPlayerQuitsActor)
{
	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, quit())
		.Times(1);

	qungeon::stream_player player(std::cin, std::cout, &actor);

	player.quit();
}

TEST(StreamPlayerTest, processQuitInput)
{
	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, quit())
		.Times(1);

	std::stringstream input("QUIT\n");
	qungeon::stream_player player(input, std::cout, &actor);

	player.process_command();
}

TEST(StreamPlayerTest, processLookInput)
{
	std::istringstream input("look\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, look(Ref(output)))
		.Times(1);

	qungeon::stream_player player(input, output, &actor);

	player.process_command();
}

TEST(StreamPlayerTest, processNorthInput)
{
	std::istringstream input("north\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_north())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(actor, north())
		.Times(1);

	qungeon::stream_player player(input, output, &actor);

	player.process_command();
}

TEST(StreamPlayerTest, processSouthInput)
{
	std::istringstream input("south\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_south())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(actor, south())
		.Times(1);

	qungeon::stream_player player(input, output, &actor);

	player.process_command();
}

TEST(StreamPlayerTest, processEastInput)
{
	std::istringstream input("east\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_east())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(actor, east())
		.Times(1);

	qungeon::stream_player player(input, output, &actor);

	player.process_command();
}

TEST(StreamPlayerTest, processWestInput)
{
	std::istringstream input("west\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_west())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(actor, west())
		.Times(1);

	qungeon::stream_player player(input, output, &actor);

	player.process_command();
}

TEST(StreamPlayerTest, processNorthInputWithNoNorth)
{
	std::istringstream input("north\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_north())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(false));
	
	qungeon::stream_player player(input, output, &actor);
	output.str("");

	player.process_command();

	EXPECT_EQ("What would you like to do?\nYou can not move that way\n", output.str());
}

TEST(StreamPlayerTest, processSouthInputWithNoSouth)
{
	std::istringstream input("south\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_south())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(false));

	qungeon::stream_player player(input, output, &actor);
	output.str("");

	player.process_command();

	EXPECT_EQ("What would you like to do?\nYou can not move that way\n", output.str());
}

TEST(StreamPlayerTest, processEastInputWithNoEast)
{
	std::istringstream input("east\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_east())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(false));

	qungeon::stream_player player(input, output, &actor);
	output.str("");

	player.process_command();

	EXPECT_EQ("What would you like to do?\nYou can not move that way\n", output.str());
}

TEST(StreamPlayerTest, processWestInputWithNoWest)
{
	std::istringstream input("west\n");
	std::ostringstream output;

	qungeon::test::mock_actor actor;
	EXPECT_CALL(actor, can_move_west())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(false));

	qungeon::stream_player player(input, output, &actor);
	output.str("");

	player.process_command();

	EXPECT_EQ("What would you like to do?\nYou can not move that way\n", output.str());
}

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

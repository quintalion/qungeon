#include <iostream>
#include <gtest/gtest.h>
#include "qungeon/stream_player.h"
#include "qungeon/room.h"

TEST(StreamPlayerTest, newPlayerIsAlive)
{
	qungeon::room start("You are in a very dark hole with no exits.  Yay?");
	qungeon::stream_player player(std::cin, std::cout, start);

	EXPECT_TRUE(player.is_alive());
}

TEST(StreamPlayerTest, quittingPlayerIsDead)
{
	qungeon::room start("You are in a very dark hole with no exits.  Yay?");
	qungeon::stream_player player(std::cin, std::cout, start);

	EXPECT_TRUE(player.is_alive());
	player.quit();
	EXPECT_FALSE(player.is_alive());
}

TEST(StreamPlayerTest, processQuitInput)
{
	qungeon::room start("You are in a very dark hole with no exits.  Yay?");
	std::stringstream input("QUIT\n");
	qungeon::stream_player player(input, std::cout, start);

	EXPECT_TRUE(player.is_alive());
	player.process_command();
	EXPECT_FALSE(player.is_alive());
}

TEST(StreamPlayerTest, processLookInput)
{
	const std::string description("You are in a very dark hole with no exits.  Yay?");
	qungeon::room start(description);
	std::istringstream input("look\n");
	std::ostringstream output;
	qungeon::stream_player player(input, output, start);

	player.process_command();
	EXPECT_EQ(std::string("What would you like to do?\n") + description + '\n', output.str());
	EXPECT_TRUE(player.is_alive());
}

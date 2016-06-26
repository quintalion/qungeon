#include "mock_room.h"
#include "qungeon/default_actor.h"
#include <gtest/gtest.h>

using ::testing::AtLeast;
using ::testing::Ref;
using ::testing::Return;

TEST(ActorTest, quit)
{
	qungeon::default_actor actor(nullptr);

	EXPECT_TRUE(actor.is_alive());
	actor.quit();
	EXPECT_FALSE(actor.is_alive());
}

TEST(ActorTest, look)
{
	std::ostringstream output;
	qungeon::test::mock_room room;
	EXPECT_CALL(room, write_description(Ref(output)))
		.Times(AtLeast(1));

	qungeon::default_actor actor(&room);
	actor.look(output);
}

TEST(ActorTest, movable)
{
	std::ostringstream output;
	qungeon::test::mock_room start_room;
	qungeon::test::mock_room new_room;

	EXPECT_CALL(new_room, write_description(Ref(output)))
		.Times(AtLeast(1));

	qungeon::default_actor actor(&start_room);
	actor.set_location(&new_room);
	actor.look(output);
}

TEST(ActorTest, north)
{
	std::ostringstream output;
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, transit_north(&actor))
		.Times(1);
	
	actor.north();
}

TEST(ActorTest, south)
{
	std::ostringstream output;
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, transit_south(&actor))
		.Times(1);

	actor.south();
}

TEST(ActorTest, east)
{
	std::ostringstream output;
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, transit_east(&actor))
		.Times(1);

	actor.east();
}

TEST(ActorTest, west)
{
	std::ostringstream output;
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, transit_west(&actor))
		.Times(1);

	actor.west();
}
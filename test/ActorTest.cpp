#include "mock_room.h"
#include "qungeon/default_actor.h"
#include "qungeon/illegal_move_exception.h"
#include <gtest/gtest.h>

using ::testing::AtLeast;
using ::testing::Ref;
using ::testing::Return;
using ::testing::Throw;

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
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, has_north_exit())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(room, transit_north(&actor))
		.Times(1);
	
	EXPECT_TRUE(actor.can_move_north());
	actor.north();
}

TEST(ActorTest, south)
{
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, has_south_exit())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(room, transit_south(&actor))
		.Times(1);

	EXPECT_TRUE(actor.can_move_south());
	actor.south();
}

TEST(ActorTest, east)
{
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, has_east_exit())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(room, transit_east(&actor))
		.Times(1);

	EXPECT_TRUE(actor.can_move_east());
	actor.east();
}

TEST(ActorTest, west)
{
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, has_west_exit())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(true));
	EXPECT_CALL(room, transit_west(&actor))
		.Times(1);

	EXPECT_TRUE(actor.can_move_west());
	actor.west();
}

TEST(ActorTest, northWithNoRoom)
{
	qungeon::test::mock_room room;
	qungeon::default_actor actor(&room);

	EXPECT_CALL(room, has_north_exit())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(false));
	EXPECT_CALL(room, transit_north(&actor))
		.Times(1)
		.WillRepeatedly(Throw(qungeon::illegal_move_exception("blah")));

	EXPECT_FALSE(actor.can_move_north());
	EXPECT_THROW(actor.north(), qungeon::illegal_move_exception);
}
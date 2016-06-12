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

TEST(ActorTest, north)
{
	std::ostringstream output;
	qungeon::test::mock_room room;
	qungeon::test::mock_room north_room;
	EXPECT_CALL(room, get_north())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(&north_room));
	EXPECT_CALL(north_room, write_description(Ref(output)))
		.Times(AtLeast(1));

	qungeon::default_actor actor(&room);
	actor.north();
	actor.look(output);
}
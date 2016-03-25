#include "mock_input_output.h"
#include "qungeon/parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ParserTest, GetCommand)
{
	qungeon::testing::mock_input_output mock_io;

	EXPECT_CALL(mock_io, read_line())
		.Times(1)
		.WillOnce(::testing::Return("QUIT"));

	qungeon::parser parser(mock_io);
	EXPECT_EQ("QUI", parser.get_command());
}

TEST(ParserTest, GetCommandCaseInsensitive)
{
	qungeon::testing::mock_input_output mock_io;

	EXPECT_CALL(mock_io, read_line())
		.Times(1)
		.WillOnce(::testing::Return("quit"));

	qungeon::parser parser(mock_io);
	EXPECT_EQ("QUI", parser.get_command());
}
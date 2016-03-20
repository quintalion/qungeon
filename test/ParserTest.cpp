#include "MockInputOutput.h"
#include "qungeon/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ParserTest, GetCommand)
{
	qungeon::testing::MockInputOutput mockIo;

	EXPECT_CALL(mockIo, ReadLine())
		.Times(1)
		.WillOnce(::testing::Return("QUIT"));

	qungeon::Parser parser(mockIo);
	EXPECT_EQ("QUI", parser.GetCommand());
}

TEST(ParserTest, GetCommandCaseInsensitive)
{
	qungeon::testing::MockInputOutput mockIo;

	EXPECT_CALL(mockIo, ReadLine())
		.Times(1)
		.WillOnce(::testing::Return("quit"));

	qungeon::Parser parser(mockIo);
	EXPECT_EQ("QUI", parser.GetCommand());
}
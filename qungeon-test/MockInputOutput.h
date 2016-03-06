#pragma once

#include "../qungeon/InputOutput.h"
#include <gmock/gmock.h>

namespace qungeon
{
namespace testing
{

class MockInputOutput : public InputOutput
{
public:
	MOCK_METHOD1(WriteLine, void(const std::string &));
	MOCK_METHOD0(ReadLine, std::string());
};

}

}

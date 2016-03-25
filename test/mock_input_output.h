#pragma once

#include "qungeon/input_output.h"
#include <gmock/gmock.h>

namespace qungeon
{
namespace testing
{

class mock_input_output : public input_output
{
public:
	MOCK_METHOD1(write_line, void(const std::string &));
	MOCK_METHOD0(read_line, std::string());
};

}

}

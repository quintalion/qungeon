#pragma once

#include "input_output.h"

namespace qungeon
{

/*
Boundary class for simple console input and output
*/
class console_input_output : public input_output
{
public:
	console_input_output() = default;
	console_input_output(const console_input_output &) = delete;
	console_input_output(console_input_output &&) = delete;

	console_input_output& operator=(const console_input_output &) = delete;
	console_input_output& operator=(console_input_output &&) = delete;

	void write_line(const std::string &) override;
	std::string read_line() override;

private:
	static constexpr size_t buffer_size = 255;

	char input_buffer[buffer_size];
};

}

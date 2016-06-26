#pragma once

#include <stdexcept>

namespace qungeon
{

class illegal_move_exception : public std::logic_error
{
public:
	explicit illegal_move_exception(const std::string& what_arg) : logic_error(what_arg) {}
	explicit illegal_move_exception(const char* what_arg) : logic_error(what_arg) {}
};

}

#pragma once

#include <istream>
#include <ostream>
#include "player.h"

namespace qungeon
{

class actor;

class stream_player : public player
{
public:
	stream_player(std::istream &input, std::ostream &output, qungeon::actor* actor);
	bool is_alive() const override;

	void quit() override;
	void process_command() override;

private:
	std::istream &input;
	std::ostream &output;
	qungeon::actor* actor;
};

}

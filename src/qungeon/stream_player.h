#pragma once

#include <istream>
#include <ostream>
#include "player.h"
#include "room.h"

namespace qungeon
{

class stream_player : public player
{
public:
	stream_player(std::istream &input, std::ostream &output, qungeon::room start_room);
	bool is_alive() const override;

	void quit() override;
	void process_command() override;

private:
	std::istream &input;
	std::ostream &output;
	qungeon::room current_room;
	bool alive = true;
};

}

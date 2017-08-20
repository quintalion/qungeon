#include "move_command.h"
#include "../actor.h"

namespace qungeon
{

	namespace command
	{

		move_command::move_command(qungeon::actor* actor, std::ostream* output)
			: actor{ actor }, output{ output }
		{}

		void move_command::execute()
		{
			const char *CAN_NOT_MOVE = "You can not move that way";

			if (can_move()) {
				move();
				actor->look(*output);
			}
			else
			{
				*output << CAN_NOT_MOVE << std::endl;
			}
		}

	}

}

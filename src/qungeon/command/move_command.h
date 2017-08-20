#pragma once

#include <ostream>

#include "command.h"

namespace qungeon
{

	class actor;

	namespace command
	{

		class move_command : public command
		{
		public:
			move_command(qungeon::actor* actor, std::ostream* output);
			~move_command() override = default;

			void execute() override;

		protected:
			virtual bool can_move() = 0;
			virtual void move() = 0;

			qungeon::actor* actor;
			std::ostream* output;
		};


	}

}

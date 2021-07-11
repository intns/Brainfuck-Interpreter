#pragma once
#include <types.hpp>
#include <iostream>

namespace bf
{
	enum class Instruction : u8
	{
		IncrementDp = 0,
		DecrementDp,
		Increment,
		Decrement,
		Output,
		Input,
		WhileStart,
		WhileEnd,

		Invalid
	};

	std::ostream& operator<<(std::ostream& stream, Instruction& inst);
}
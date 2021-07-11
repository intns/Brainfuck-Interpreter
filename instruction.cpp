#include <instruction.hpp>

namespace bf
{
	std::ostream& operator<<(std::ostream& stream, Instruction& inst)
	{
		switch (inst)
		{
		case bf::Instruction::IncrementDp:
			stream << "[IncrementDataPointer]";
			break;
		case bf::Instruction::DecrementDp:
			stream << "[DecrementDataPointer]";
			break;
		case bf::Instruction::Increment:
			stream << "[IncrementByte]";
			break;
		case bf::Instruction::Decrement:
			stream << "[DecrementByte]";
			break;
		case bf::Instruction::Output:
			stream << "[Output]";
			break;
		case bf::Instruction::Input:
			stream << "[Input]";
			break;
		case bf::Instruction::WhileStart:
			stream << "[WhileStart]";
			break;
		case bf::Instruction::WhileEnd:
			stream << "[WhileEnd]";
			break;
		case bf::Instruction::Invalid:
			stream << "[Invalid]";
			break;
		default:
			break;
		}

		return stream;
	}
}
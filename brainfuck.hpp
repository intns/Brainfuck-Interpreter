#pragma once
#include <vector>
#include <unordered_map>
#include <instruction.hpp>
#include <types.hpp>

namespace bf
{
	class BrainFuck
	{
	private:
		std::vector<u8> m_cells;
		std::vector<Instruction> m_instructions;
		std::size_t m_index = 0;

		std::unordered_map<u8, Instruction> m_conversionTable = {
			{'>', Instruction::IncrementDp},
			{'<', Instruction::DecrementDp},
			{'+', Instruction::Increment},
			{'-', Instruction::Decrement},
			{'.', Instruction::Output},
			{',', Instruction::Input},
			{'[', Instruction::WhileStart},
			{']', Instruction::WhileEnd},
		};
	public:
		BrainFuck() : m_cells(0x100) {}
		BrainFuck(std::size_t cellSize) : m_cells(cellSize) {}
		~BrainFuck() = default;

		const std::size_t getIndex() const { return m_index; }
		const std::vector<u8>& getCells() const { return m_cells; }
		const std::vector<Instruction>& getInstructions() const { return m_instructions; }

		const Instruction identifyInstruction(u8 toIdentify) const;

		void read(const char* input);
	};

	static std::ostream& operator<<(std::ostream& stream, BrainFuck& bf);
}
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

		std::FILE* m_inputStream = nullptr;

		const std::unordered_map<u8, Instruction> m_conversionTable = {
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
		BrainFuck(std::size_t cellSize = 0x100, std::FILE* input = stdin) : m_cells(cellSize), m_inputStream(input) {}
		~BrainFuck() = default;
		BrainFuck(const BrainFuck&) = delete;
		BrainFuck& operator=(const BrainFuck&) = delete;

		inline const std::size_t getIndex() const { return m_index; }
		inline const std::vector<u8>& getCells() const { return m_cells; }
		inline const std::vector<Instruction>& getInstructions() const { return m_instructions; }
		inline const std::unordered_map<u8, Instruction>& getConversionTable() const { return m_conversionTable; }

		const Instruction identifyInstruction(u8 toIdentify) const;

		void clear(const bool resetCells = true);
		void read(const char* input);
		void execute();
	};

	std::ostream& operator<<(std::ostream& stream, BrainFuck& bf);
}
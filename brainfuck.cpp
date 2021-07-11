#include <brainfuck.hpp>

namespace bf
{
	const Instruction BrainFuck::identifyInstruction(u8 toIdentify) const
	{
		if (m_conversionTable.contains(toIdentify))
		{
			return m_conversionTable.at(toIdentify);
		}

		return Instruction::Invalid;
	}

	void BrainFuck::clear(const bool resetCells)
	{
		if (resetCells)
		{
			std::fill(m_cells.begin(), m_cells.end(), 0);
		}

		m_instructions.clear();
	}

	void BrainFuck::read(const char* input)
	{
		for (std::size_t i = 0; input[i]; i++)
		{
			m_instructions.push_back(identifyInstruction(input[i]));
		}
	}

	void BrainFuck::execute()
	{
		for (std::size_t i = 0; i < m_instructions.size(); i++)
		{
			const Instruction curInstruction = m_instructions[i];

			switch (curInstruction)
			{
			case bf::Instruction::IncrementDp:
				m_index++;
				break;
			case bf::Instruction::DecrementDp:
				m_index--;
				break;
			case bf::Instruction::Increment:
				m_cells[m_index]++;
				break;
			case bf::Instruction::Decrement:
				m_cells[m_index]--;
				break;
			case bf::Instruction::Output:
				std::cout << m_cells[m_index];
				break;
			case bf::Instruction::Input:
				m_cells[m_index] = std::getc(m_inputStream);
				break;
			case bf::Instruction::WhileStart:
				continue;
			case bf::Instruction::WhileEnd:
				if (m_cells[m_index])
				{
					std::size_t loopIdx = 1;
					while (loopIdx > 0)
					{
						const Instruction prevInst = m_instructions[--i];
						if (prevInst == Instruction::WhileStart)
						{
							loopIdx--;
						}
						else if (prevInst == Instruction::WhileEnd)
						{
							loopIdx++;
						}
					}
				}
				break;

			case bf::Instruction::Invalid:
			default:
				break;
			}
		}
	}

	std::ostream& operator<<(std::ostream& stream, BrainFuck& bf)
	{
		const std::vector<u8>& cells = bf.getCells();
		for (std::size_t i = 0; i < cells.size(); i++)
		{
			stream << "CELL [" << i << "] [" << (u32)cells[i] << "]\n";
		}
		return stream;
	}
}
#include <brainfuck.hpp>

namespace bf
{
	std::ostream& operator<<(std::ostream& stream, BrainFuck& bf)
	{
		const std::vector<u8>& cells = bf.getCells();
		for (std::size_t i = 0; i < cells.size(); i++)
		{
			stream << "CELL [" << i << "] [" << cells[i] << "]\n";
		}
		return stream;
	}

	const Instruction BrainFuck::identifyInstruction(u8 toIdentify) const
	{
		if (m_conversionTable.contains(toIdentify))
		{
			return m_conversionTable.at(toIdentify);
		}
		return Instruction::Invalid;
	}

	void BrainFuck::read(const char* input)
	{
		for (std::size_t i = 0; input[i]; i++)
		{
			const char inputC = input[i];
			const Instruction convInstruction = identifyInstruction(inputC);
			m_instructions.push_back(convInstruction);

			switch (convInstruction)
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
				m_cells[m_index] = std::getc(stdin);
				break;
			case bf::Instruction::WhileStart:
				continue;
			case bf::Instruction::WhileEnd:
				if (m_cells[m_index])
				{
					std::size_t loopIdx = 1;
					while (loopIdx > 0)
					{
						const char backChar = input[--i];
						if (backChar == '[')
						{
							loopIdx--;
						}
						else if (backChar == ']')
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

}
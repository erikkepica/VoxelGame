#include "Block.h"
namespace Kepeca
{
	BlockList::BlockList()
	{
		m_Blocks.push_back(Block(m_Blocks.size(), "GRASS_BLOCK", "Grass Block"));
		m_Blocks.push_back(Block(m_Blocks.size(), "STONE", "Stone"));
	}


	Block BlockList::GetBlock(uint16_t ID)
	{
		for (auto blck : m_Blocks)
		{
			if (blck.ID == ID)
			{
				return blck;
			}
		}
	}
	Block BlockList::GetBlock(std::string ID)
	{
		for (auto blck : m_Blocks)
		{
			if (blck.stringID == ID)
			{
				return blck;
			}
		}
	}
	Block::Block(uint16_t ID, std::string stringID, std::string name)
		:ID(ID),stringID(stringID),name(name)
	{
	}
}

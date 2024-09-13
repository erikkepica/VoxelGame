#include "Block.h"
namespace Kepeca
{
	BlockList::BlockList()
	{
		AddBlock("GRASS_BLOCK", "Grass Block");
		AddBlock("STONE", "Stone");
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
	void BlockList::AddBlock(std::string ID, std::string name)
	{
		m_Blocks.push_back(Block(m_Blocks.size() + 1, ID, name));
	}
	Block::Block(uint16_t ID, std::string stringID, std::string name)
		:ID(ID),stringID(stringID),name(name)
	{
	}
}

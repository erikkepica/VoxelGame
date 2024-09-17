#include "Block.h"
namespace Kepeca
{
	void BlockList::InitBlocks()
	{
		AddBlock("GRASS_BLOCK", "Grass Block", false);
		AddBlock("STONE", "Stone", false);
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
		throw("");
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
		throw("");
	}

	void BlockList::AddBlock(std::string ID, std::string name, bool transparent)
	{
		m_Blocks.push_back(Block(m_Blocks.size() + 1, ID, name, transparent));
	}
	Block::Block(uint16_t ID, std::string stringID, std::string name, bool transparent)
		:ID(ID),stringID(stringID),name(name),transparent(transparent)
	{
	}
}

#pragma once
#include<string>
#include<vector>
#include<memory>

namespace Kepeca
{
	class Block
	{
	public:
		Block(uint16_t ID, std::string stringID, std::string name);

		uint16_t ID;
		std::string stringID;
		
		std::string name;
	private:

	};

	class BlockList
	{
	public:
		BlockList();
		Block GetBlock(uint16_t ID);
		Block GetBlock(std::string ID);

	private:
		std::vector<Block> m_Blocks;
	};
}
#pragma once
#include<string>
#include<vector>
#include<memory>

namespace Kepeca
{
	class Block
	{
	public:
		Block(uint16_t ID, std::string stringID, std::string name, bool transparent);

		uint16_t ID;
		std::string stringID;
		
		std::string name;

		bool transparent;
	private:

	};

	class BlockList
	{
	public:
		static void InitBlocks();
		static Block GetBlock(uint16_t ID);
		static Block GetBlock(std::string ID);

		static void AddBlock(std::string ID, std::string name, bool transparen);

		static inline std::vector<Block> m_Blocks;
	};
}
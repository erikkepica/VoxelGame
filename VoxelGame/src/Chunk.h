#pragma once
#include"RenderObject.h"
#include"Block.h"
#include<array>

namespace Kepeca
{
	class Chunk : public RenderObject
	{
	public:
		Chunk(glm::ivec3 size);

		void Build();

		int PosToIndex(glm::ivec3 pos);
	private:
		uint16_t* m_BlockArray;
		glm::ivec3 m_Size;
	};
}
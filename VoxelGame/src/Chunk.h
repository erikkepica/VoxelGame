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
	private:
		uint16_t* m_BlockArray;
		glm::ivec3 m_Size;
	};
}
#pragma once
#include"RenderObject.h"
#include<array>

namespace Kepeca
{
	class Face
	{
	public:
		enum FaceType
		{
			front,
			back,
			right,
			left,
			top,
			bottom,
			SIZE
		};
		inline const static std::vector<unsigned int> m_Indices
		{
			0,1,3,
			1,2,3
		};

		inline const static std::unordered_map<FaceType, std::vector<float>> m_FaceVerticiesMap
		{
			{front,{
			-0.5f, -0.5f, 0.5f,
			0.5f, -0.5f, 0.5f,
			0.5f,  0.5f, 0.5f,
			-0.5f,  0.5f, 0.5f
			}},
			{back,{
			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f
			}},
			{right,{
			0.5f, -0.5f, 0.5f,
			0.5f, -0.5f, -0.5f,
			0.5f,  0.5f, -0.5f,
			0.5f,  0.5f, 0.5f
			}},
			{left,{
			-0.5f, -0.5f, 0.5f,
			-0.5f, -0.5f, -0.5f,
			-0.5f,  0.5f, -0.5f,
			-0.5f,  0.5f, 0.5f
			}},
			{top,{
			-0.5f, 0.5f, -0.5f,
			-0.5f,  0.5f, 0.5f,
			0.5f,  0.5f, 0.5f,
			0.5f, 0.5f, -0.5f
			}},
			{bottom,{
			-0.5f, -0.5f, -0.5f,
			-0.5f,  -0.5f, 0.5f,
			0.5f,  -0.5f, 0.5f,
			0.5f, -0.5f, -0.5f
			}},
		};
		inline const static std::unordered_map<FaceType, std::vector<float>> m_FaceUVMap
		{
			{front,{
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f
			}},
			{back,{
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f
			}},
			{right,{
			1.0f, 0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f
			}},
			{left,{
			1.0f, 0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f
			}},
			{top,{
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f
			}},
			{bottom,{
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f
			}},
		};
		inline const static std::unordered_map<FaceType, std::vector<float>> m_FaceNormalsMap
		{
			{front,{
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f
			}},
			{back,{
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f,
			0.0f, 0.0f, -1.0f
			}},
			{right,{
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f
			}},
			{left,{
			-1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f
			}},
			{ top,{
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
			} },
			{ bottom,{
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f
			} },
		};
	};

	class Chunk : public RenderObject
	{
	public:
		Chunk(glm::ivec3 size);

		void Build();

		int PosToIndex(glm::ivec3 pos);

		bool FaceVisibility(glm::ivec3 pos, Face::FaceType face);
	private:
		uint16_t* m_BlockArray;
		glm::ivec3 m_Size;
	};
}
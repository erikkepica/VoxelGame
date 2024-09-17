#include "Chunk.h"
#include<vector>
#include<unordered_map>
#include"Log.h"
#include"Block.h"

namespace Kepeca
{


	Chunk::Chunk(glm::ivec3 size)
		:m_Size(size)
	{
		m_BlockArray = new uint16_t[size.x * size.z * size.y];
		for (int x = 0; x < m_Size.x; x++)
		{
			for (int y = 0; y < m_Size.y; y++)
			{
				for (int z = 0; z < m_Size.z; z++)
				{
					int i = PosToIndex(glm::ivec3(x, y, z));


					int nx = x - size.x / 2;
					int ny = y - size.y / 2;
					int nz = z - size.z / 2;

					int dist = glm::distance(glm::vec3(nx, ny, nz), glm::vec3(0.0f));

					if (dist > 0.5f * m_Size.x)
					{
						m_BlockArray[i] = 0;
					}
					else
					{
						if (glm::distance(glm::vec2(nx, ny), glm::vec2(0, 0)) < 5)
						{
							LOG_TRACE("Generating ... Progress: {0}", 100.f * (float)i / (float)(size.x * size.y * size.z));

							m_BlockArray[i] = 0;
						}
						else if (glm::distance(glm::vec2(nz, ny), glm::vec2(0, 0)) < 5)
						{
							m_BlockArray[i] = 0;
						}
						else if (glm::distance(glm::vec2(nx, nz), glm::vec2(0, 0)) < 5)
						{
							m_BlockArray[i] = 0;
						}
						else
						{
							m_BlockArray[i] = 2;
						}
					}
				}
			}
		}
		Build();
	}

	void Chunk::Build()
	{
		std::vector<float> vertices;
		std::vector<int> indices;

		for (int x = 0; x < m_Size.x; x++)
		{
			for (int y = 0; y < m_Size.y; y++)
			{
				for (int z = 0; z < m_Size.z; z++)
				{
					if (m_BlockArray[PosToIndex(glm::ivec3(x, y, z))] == 0)
						continue;
					for (int f = 0; f < Face::SIZE; f++)
					{
						if (!FaceVisibility(glm::vec3(x, y, z), static_cast<Face::FaceType>(f)))
						{
							continue;
						}
						int indSize = vertices.size()/8;
						for (int i = 0; i < 6; i++)
						{
							//Could lead to problems 
							indices.push_back(Face::m_Indices[i]+ indSize);
						}
						for (int v = 0; v < 4; v++)
						{
							vertices.push_back(Face::m_FaceVerticiesMap.at(static_cast<Face::FaceType>(f)).at(v * 3)+x);
							vertices.push_back(Face::m_FaceVerticiesMap.at(static_cast<Face::FaceType>(f)).at(v * 3+1)+y);
							vertices.push_back(Face::m_FaceVerticiesMap.at(static_cast<Face::FaceType>(f)).at(v * 3+2)+z);

							vertices.push_back(Face::m_FaceUVMap.at(static_cast<Face::FaceType>(f)).at(v * 2));
							vertices.push_back(Face::m_FaceUVMap.at(static_cast<Face::FaceType>(f)).at(v * 2+1));

							vertices.push_back(Face::m_FaceNormalsMap.at(static_cast<Face::FaceType>(f)).at(v * 3));
							vertices.push_back(Face::m_FaceNormalsMap.at(static_cast<Face::FaceType>(f)).at(v * 3+1));
							vertices.push_back(Face::m_FaceNormalsMap.at(static_cast<Face::FaceType>(f)).at(v * 3+2));
						}
					}
				}
			}
		}
		Init(vertices.data(), vertices.size()*sizeof(float), indices.data(), indices.size() * sizeof(int), "res/shaders/default.vert", "res/shaders/default.frag", "res/textures/blocks/STONE.png");
	}

	int Chunk::PosToIndex(glm::ivec3 pos)
	{
		return pos.x * m_Size.x * m_Size.z + pos.y * m_Size.z + pos.z;
	}

	bool Chunk::FaceVisibility(glm::ivec3 pos, Face::FaceType face)
	{
		if ((pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2])).x < 0 || (pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2])).x > m_Size.x - 1 ||
			(pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2])).y < 0 || (pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2])).y > m_Size.x - 1 ||
			(pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2])).z < 0 || (pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2])).z > m_Size.x - 1)
		{
			return true;
		}
		if (BlockList::GetBlock(m_BlockArray[PosToIndex(pos)]).transparent)
		{
			return true;
		}
		if (m_BlockArray[PosToIndex(pos + glm::ivec3(Face::m_FaceNormalsMap.at(face)[0], Face::m_FaceNormalsMap.at(face)[1], Face::m_FaceNormalsMap.at(face)[2]))] == 0)
		{
			return true;
		}
		return false;
	}

}
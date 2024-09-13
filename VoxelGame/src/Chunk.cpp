#include "Chunk.h"
#include<vector>
#include<unordered_map>

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
			{top,{
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
			}},
			{bottom,{
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f
			}},
		};
	};
	float g_CubeVertices[] = {
		//      COORDS          UV              NORMAL
		//front
		-0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // left  
		 0.5f, -0.5f,  0.5f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // right 
		 0.5f,  0.5f,  0.5f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,  // top right
		-0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f,  // top left

		//left
		-0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f, // back left 
		-0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   -1.0f, 0.0f, 0.0f, // left  
		-0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f, // top left
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   -1.0f, 0.0f, 0.0f, // top back left

		//back
		 0.5f, -0.5f, -0.5f,   0.0f, 0.0f,   0.0f, 0.0f, -1.0f,  // back right 
		-0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,  // back left
		-0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   0.0f, 0.0f, -1.0f,  // top back left 
		 0.5f,  0.5f, -0.5f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,  // top back right

		 //right
		 0.5f, -0.5f, -0.5f,   1.0f, 0.0f,   1.0f, 0.0f, 0.0f, // back left 
		 0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f, // left  
		 0.5f,  0.5f,  0.5f,   0.0f, 1.0f,   1.0f, 0.0f, 0.0f, // top left
		 0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f, // top back left

		 //top
		 -0.5f,  0.5f,  0.5f,   0.0f, 0.0f,   0.0f, 1.0f, 0.0f,  // top left  
		  0.5f,  0.5f,  0.5f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,  // top right 
		  0.5f,  0.5f, -0.5f,   1.0f, 1.0f,   0.0f, 1.0f, 0.0f,  // top back right
		 -0.5f,  0.5f, -0.5f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,  // top back left

		 //bottom
		 -0.5f, -0.5f,  0.5f,   0.0f, 0.0f,   0.0f, -1.0f, 0.0f,  // top left  
		  0.5f, -0.5f,  0.5f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,  // top right 
		  0.5f, -0.5f, -0.5f,   1.0f, 1.0f,   0.0f, -1.0f, 0.0f,  // top back right
		 -0.5f, -0.5f, -0.5f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,  // top back left
	};

	int g_CubeIndices[] = {
		0,1,3,
		1,2,3,
		4,5,7,
		5,6,7,
		8,9,11,
		9,10,11,
		12,13,15,
		13,14,15,
		16,17,19,
		17,18,19,
		20,21,23,
		21,22,23
	};

	Chunk::Chunk(glm::ivec3 size)
		:m_Size(size)
	{
		m_BlockArray = new uint16_t[size.x * size.z * size.y];
		for (int i = 0; i < size.x * size.z * size.y; i++)
		{
			m_BlockArray[i] = 0;
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
					for (int f = 0; f < Face::SIZE; f++)
					{
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
		Init(vertices.data(), vertices.size(), indices.data(), indices.size(), "res/shaders/default.vert", "res/shaders/default.frag", "res/textures/blocks/grass.png");
	}

}
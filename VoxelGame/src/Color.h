#pragma once
#include<glm/vec4.hpp>

namespace Kepeca
{
	struct Color
	{
		Color();
		Color(float r, float g, float b, float a, bool normalized);
		Color(glm::vec4 col, bool normalized);

		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;
		float a = 0.0f;

		bool normalized = false;

		glm::vec4 GetColorVector();

		void NormalizeColor();
		void UnNormalizeColor();
	};
}


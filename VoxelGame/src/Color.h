#pragma once
#include<glm/vec4.hpp>

namespace Kepeca
{
	struct Color
	{
		Color();
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool normalized);
		Color(glm::vec4 col, bool normalized);

		uint8_t r = 0.0f;
		uint8_t g = 0.0f;
		uint8_t b = 0.0f;
		uint8_t a = 0.0f;

		bool normalized = false;

		static glm::vec4 GetColorVector(Color col);

		static Color NormalizeColor(Color col);
		static Color UnNormalizeColor(Color col);
	};
}


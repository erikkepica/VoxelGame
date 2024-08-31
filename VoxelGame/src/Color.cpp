#include "Color.h"

namespace Kepeca
{
	Color::Color()
	{
	}
	Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a, bool normalized)
		: r(r),g(g),b(b),a(a),normalized(normalized)
	{
	}
	Color::Color(glm::vec4 col, bool normalized)
		:r(col.x),g(col.y),b(col.z),a(col.w),normalized(normalized)
	{
	}



	glm::vec4 Color::GetColorVector(Color col)
	{
		return glm::vec4(col.r, col.g, col.b, col.a);
	}
	Color Color::NormalizeColor(Color col)
	{
		return Color(col.r/255, col.g/255, col.b/255, col.a/255, true);
	}



	Color Color::UnNormalizeColor(Color col)
	{
		return Color(col.r * 255, col.g * 255, col.b * 255, col.a * 255, false);
	}
}
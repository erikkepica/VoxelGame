#include "Color.h"

namespace Kepeca
{
	Color::Color()
	{
	}
	Color::Color(float r, float g, float b, float a, bool normalized)
		: r(r),g(g),b(b),a(a),normalized(normalized)
	{
	}
	Color::Color(glm::vec4 col, bool normalized)
		:r(col.x),g(col.y),b(col.z),a(col.w),normalized(normalized)
	{
	}



	glm::vec4 Color::GetColorVector()
	{
		return glm::vec4(r, g, b, a);
	}


	void Color::NormalizeColor()
	{
		r /= 255;
		g /= 255;
		b /= 255;
		a /= 255;
		normalized = true;
	}
	void Color::UnNormalizeColor()
	{
		r *= 255;
		g *= 255;
		b *= 255;
		a *= 255;
		normalized = false;
	}
}
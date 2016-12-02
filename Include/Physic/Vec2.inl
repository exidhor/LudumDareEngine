inline Vec2::Vec2()
	: Vec2(0, 0)
{
	// nothing
}

Vec2::Vec2(float x, float y)
	: x(x), y(y)
{
	// nothing
}

inline Vec2::Vec2(sf::Vector2f const& vector2f)
	: Vec2(vector2f.x, vector2f.y)
{
	// nothing
}

Vec2::operator sf::Vector2f() const
{
	return sf::Vector2f(x, y);
}

void Vec2::Clear()
{
	x = 0;
	y = 0;
}

float Vec2::Length() const
{
	return (float) sqrt(SquareLength());
}

float Vec2::SquareLength() const
{
	return x*x + y*y;
}

void Vec2::Normalise()
{
	float length = this->Length();

	if (length != 0)
	{
		x = x / length;
		y = y / length;
	}
}

inline Vec2 operator -(const Vec2& right)
{
	return Vec2(-right.x, -right.y);
}

inline Vec2& operator +=(Vec2& left, const Vec2& right)
{
	left.x += right.x;
	left.y += right.y;

	return left;
}

inline Vec2& operator -=(Vec2& left, const Vec2& right)
{
	left.x -= right.x;
	left.y -= right.y;

	return left;
}

inline Vec2 operator +(const Vec2& left, const Vec2& right)
{
	return Vec2(left.x + right.x, left.y + right.y);
}

inline Vec2 operator -(const Vec2& left, const Vec2& right)
{
	return Vec2(left.x - right.x, left.y - right.y);
}

inline Vec2 operator *(const Vec2& left, float right)
{
	return Vec2(left.x * right, left.y * right);
}

inline Vec2 operator *(float left, const Vec2& right)
{
	return Vec2(right.x * left, right.y * left);
}

inline Vec2& operator *=(Vec2& left, float right)
{
	left.x *= right;
	left.y *= right;

	return left;
}

inline Vec2 operator /(const Vec2& left, float right)
{
	return Vec2(left.x / right, left.y / right);
}

inline Vec2& operator /=(Vec2& left, float right)
{
	left.x /= right;
	left.y /= right;

	return left;
}

inline bool operator ==(const Vec2& left, const Vec2& right)
{
	return (left.x == right.x)
		&& (left.y == right.y);
}

inline bool operator !=(const Vec2& left, const Vec2& right)
{
	return (left.x != right.x)
		|| (left.y != right.x);
}
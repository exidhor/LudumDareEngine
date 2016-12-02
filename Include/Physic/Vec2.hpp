#pragma once
#ifndef __VEC_2_HPP
#define __VEC_2_HPP

#include <cmath>
#include <SFML/System/Vector2.hpp>

class Vec2
{
public :
	Vec2();

	Vec2(float x, float y);
	Vec2(sf::Vector2f const& vector2f);

	float x;
	float y;

	operator sf::Vector2f() const;

	void Clear();

	float Length() const;

	float SquareLength() const;

	void Normalise();
};

Vec2 operator -(const Vec2& right);
Vec2& operator +=(Vec2& left, const Vec2& right);
Vec2& operator -=(Vec2& left, const Vec2& right);
Vec2 operator +(const Vec2& left, const Vec2& right);
Vec2 operator -(const Vec2& left, const Vec2& right);
Vec2 operator *(const Vec2& left, float right);
Vec2 operator *(float left, const Vec2& right);
Vec2& operator *=(Vec2& left, float right);
Vec2 operator /(const Vec2& left, float right);
Vec2& operator /=(Vec2& left, float right);

bool operator ==(const Vec2& left, const Vec2& right);
bool operator !=(const Vec2& left, const Vec2& right);

#include "Physic/Vec2.inl"

#endif // __VEC_2_HPP
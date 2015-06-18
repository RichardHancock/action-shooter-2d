#pragma once

#include <iostream>
#include <cmath>

//Self Reference: This code was used in a previous assignment.

/**
@brief Stores a 2D Vector or Position, as floats
*/
class Vec2
{
	//Used to be a Struct but had so much functionality and complexity I converted it to a class
	
public:
	///X Pos
	float x;

	///Y Pos
	float y;

	/**
	@brief Create a Vec2
	*/
	Vec2()
	{

	}

	/**
	@brief Create a Vec2
	@param float - x value
	@param float - y value
	*/
	Vec2(float initX, float initY)
	{
		x = initX;
		y = initY;
	}

	/**
	@brief Create a Vec2
	@param float - X and Y value
	*/
	Vec2(float XY)
	{
		x = XY;
		y = XY;
	}

	/**
	@brief Get the length of the vector
	@return float - length of vector
	*/
	float getLength()
	{
		Vec2 temp;
		temp.x = pow(x, 2);
		temp.y = pow(y, 2);
		float total = temp.x + temp.y;
		return sqrt(total);
	}

	/**
	@brief Get a normalized Vec2
	@return Vec2 - Normalized vector
	*/
	Vec2 normalize()
	{
		float length = getLength();
		return Vec2(x / length, y / length);
	}


	//Operator Overloading
	
	Vec2* operator += (Vec2 b)
	{
		x += b.x;
		y += b.y;
		return this;
	}
	Vec2* operator -= (Vec2 b)
	{
		x -= b.x;
		y -= b.y;
		return this;
	}
	Vec2* operator *= (Vec2 b)
	{
		x *= b.x;
		y *= b.y;
		return this;
	}
	Vec2* operator /= (Vec2 b)
	{
		x /= b.x;
		y /= b.y;
		return this;
	}
	Vec2* operator = (int b)
	{
		x = (float)b;
		y = (float)b;
		return this;
	}

	inline Vec2 operator + (Vec2 b)
	{
		Vec2 result;
		result.x = x + b.x;
		result.y = y + b.y;
		return result;
	}
	inline Vec2 operator - (Vec2 b)
	{
		Vec2 result;
		result.x = x - b.x;
		result.y = y - b.y;
		return result;
	}
	inline Vec2 operator / (Vec2 b)
	{
		Vec2 result;
		result.x = x / b.x;
		result.y = y / b.y;
		return result;
	}
	inline Vec2 operator * (Vec2 b)
	{
		Vec2 result;
		result.x = x * b.x;
		result.y = y * b.y;
		return result;
	}
	inline Vec2 operator * (int b)
	{
		Vec2 result;
		result.x = x * b;
		result.y = y * b;
		return result;
	}
	inline Vec2 operator * (float b)
	{
		Vec2 result;
		result.x = x * b;
		result.y = y * b;
		return result;
	}

	

};


inline std::ostream &operator << (std::ostream& os, Vec2& a)
{
	os << "Vec2(" << a.x << "," << a.y << ") ";
	return os;
}
inline bool operator == (const Vec2& a, const Vec2& b)
{
	return (a.x == b.x && a.y == b.y) ? true : false;
}
inline bool operator != (const Vec2& a, const Vec2& b)
{
	return (a.x != b.x || a.y != b.y) ? true : false;
}

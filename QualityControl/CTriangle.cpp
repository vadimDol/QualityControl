#include "stdafx.h"
#include "CTriangle.h"

CTriangle::CTriangle(SideLength const& sideLength)
	:m_sideLength(sideLength)
{}

bool CTriangle::IsTriangle()
{
	return (m_sideLength.a < m_sideLength.b + m_sideLength.c)
		&& (m_sideLength.b < m_sideLength.a + m_sideLength.c) 
		&& (m_sideLength.c < m_sideLength.a + m_sideLength.b);
}

bool CTriangle::IsTriangleIsosceles()
{
	return (m_sideLength.a == m_sideLength.b) 
		|| (m_sideLength.b == m_sideLength.c) 
		|| (m_sideLength.c == m_sideLength.a);
}

bool CTriangle::IsTriangleEquilateral()
{
	return (m_sideLength.a == m_sideLength.b)
		&& (m_sideLength.b == m_sideLength.c)
		&& (m_sideLength.c == m_sideLength.a);
}

TriangleType CTriangle::GetTriangleType()
{
	TriangleType triangleType;
	if (!IsTriangle())
	{
		triangleType = TriangleType::NOT_TRIANGLE;
	}
	else if (IsTriangleEquilateral())
	{
		triangleType = TriangleType::EQUILATERAL;
	}
	else if (IsTriangleIsosceles())
	{
		triangleType = TriangleType::ISOSCELES;
	}
	else
	{
		triangleType = TriangleType::COMMON;
	}
	return triangleType;
}
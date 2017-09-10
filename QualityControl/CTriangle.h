#pragma once

enum class TriangleType
{
	COMMON,
	ISOSCELES,
	EQUILATERAL,
	NOT_TRIANGLE
};

typedef std::map<TriangleType, std::string> TriangleTypeMap;

const TriangleTypeMap TRIANGLE_TYPE_MAP = {
	{ TriangleType::COMMON, "Обычный" },
	{ TriangleType::ISOSCELES, "Равнобедренный" },
	{ TriangleType::EQUILATERAL, "Равносторонний" },
	{ TriangleType::NOT_TRIANGLE, "Не треугольник" },
};

struct SideLength
{
	int a;
	int b;
	int c;
};

class CTriangle
{
public:
	CTriangle(SideLength const& sideLength);
	TriangleType GetTriangleType();
private:
	SideLength m_sideLength;

	bool IsTriangle();
	bool IsTriangleIsosceles();
	bool IsTriangleEquilateral();
};
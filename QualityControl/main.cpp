// QualityControl.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "CTriangle.h"
#include <stdexcept>

enum class TypeError
{
	INVALID_NUMBER_OF_PARAMETERS,
	INVALID_CHARACTERS_IN_PARAMETERS,
	NEGATIVE_NUMBERS_IN_PARAMETERS,
	OUT_OF_RANGE,
	NO_ERROR
};

typedef std::map<TypeError, std::string> TypeErrorMap;

const TypeErrorMap TYPE_ERROR_MAP = {
	{ TypeError::INVALID_NUMBER_OF_PARAMETERS, "”кажите длины сторон в качестве параметров. ‘ормат ввода: triangle.exe a b c" },
	{ TypeError::INVALID_CHARACTERS_IN_PARAMETERS, "¬ качестве длины сторон, могут быть только числа!" },
	{ TypeError::NEGATIVE_NUMBERS_IN_PARAMETERS, "¬ качестве длины сторон, могут быть только положительные числа!" },
	{ TypeError::OUT_OF_RANGE, "ћаксимальное значение длины сторон равен " + std::to_string(INT_MAX) },
};

void PrintError(TypeError error)
{
	std::cout << TYPE_ERROR_MAP.at(error) << std::endl;
}

bool IsNegativeNumbers(SideLength const& sideLength)
{
	return (sideLength.a < 0) || (sideLength.b < 0) || (sideLength.c < 0);
}

void CheckInvalidCharacters(std::string const& str1, std::string const& str2, std::string const& str3)
{
	std::string allStr = str1 + str2 + str3;
	for (auto ch : allStr)
	{
		if (isalpha((unsigned char)ch))
		{
			throw std::invalid_argument("");
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 4)
	{
		PrintError(TypeError::INVALID_NUMBER_OF_PARAMETERS);
		return 1;
	}
	
	SideLength sideLength;
	try
	{
		CheckInvalidCharacters(argv[1], argv[2], argv[3]);
		sideLength.a = std::stoi(argv[1]);
		sideLength.b = std::stoi(argv[2]);
		sideLength.c = std::stoi(argv[3]);
	}
	catch (std::invalid_argument& ex)
	{
		PrintError(TypeError::INVALID_CHARACTERS_IN_PARAMETERS);
		return 1;
	}
	catch (std::out_of_range& ex)
	{
		PrintError(TypeError::OUT_OF_RANGE);
		return 1;
	}

	if (IsNegativeNumbers(sideLength))
	{
		PrintError(TypeError::NEGATIVE_NUMBERS_IN_PARAMETERS);
		return 1;
	}

	CTriangle triangle(sideLength);
	std::cout << TRIANGLE_TYPE_MAP.at(triangle.GetTriangleType()) << std::endl;

    return 0;
}


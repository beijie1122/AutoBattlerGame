#pragma once
#include <vector>
#include <string>

struct Point
{
	int x;
	int y;
};

class Renderer
{
public:

	Renderer();

	~Renderer();

	void DrawCardVector(const std::vector<std::vector<char>>& vec, const Point& position, int VerticleMeasure, int HorizontalMeasure);

	void DrawCardIntValue(const int& Value, const Point& position);

	void DrawStringValue(const std::string& Value, const Point& position);


};

void InitializeRenderer();


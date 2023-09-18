#include "Renderer.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <thread>
#include <vector>

Renderer::Renderer()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	LockWindowUpdate(GetConsoleWindow());
	system("CLS");
}

Renderer::~Renderer()
{
	LockWindowUpdate(NULL);
}

bool SetCursorToPosition(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
	

void Renderer::DrawCardVector(const std::vector<std::vector<char>>& vec, const Point& position, int VerticleMeasure, int HorizontalMeasure)
{
	int IterateY = 0;
	SetCursorToPosition(position.x, position.y);

	for (size_t i = 0; i < VerticleMeasure; i++)
	{
		for (size_t j = 0; j < HorizontalMeasure; j++)
		{
			std::cout << vec[i][j];
		}
		IterateY++;
		SetCursorToPosition(position.x, position.y + IterateY);
	}
}

void Renderer::DrawCardIntValue(const int& Value, const Point& position)
{
	SetCursorToPosition(position.x, position.y);
	std::cout << Value;
}

void Renderer::DrawStringValue(const std::string& Value, const Point& position)
{
	SetCursorToPosition(position.x, position.y);
	std::cout << Value;
}


void InitializeRenderer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;

	SetConsoleCursorInfo(hOut, &ConCurInf);
}

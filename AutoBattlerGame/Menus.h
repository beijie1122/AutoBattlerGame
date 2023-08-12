#pragma once
#include "Renderer.h"
#include "Node.h"
#include <vector>
#include <string>

class Menus
{
public:

	int BigButtonHorizontalMeasure = 30;

	int BigButtonVerticleMeasure = 5;

	int ChoiceOutlineHorizontalMeasure = BigButtonHorizontalMeasure + 4;

	int ChoiceOutlineVerticleMeasure = BigButtonVerticleMeasure + 2;

	std::vector<std::vector<char>> BigButttonLayout{ BigButtonVerticleMeasure, std::vector<char>(BigButtonHorizontalMeasure) };

	std::vector<std::vector<char>> ChoiceOutlineLayout{ ChoiceOutlineVerticleMeasure, std::vector<char>(ChoiceOutlineHorizontalMeasure) };

	std::vector<std::string> MenuButtonText = { "Start Battle", "View Cards", "View Bestiary" };

	std::vector<int> MenuRenderYCoords{ 5, 11, 17 };

	int MenuRenderXCoord = 5;

	Menus();

	void MainGameMenu(Renderer MenuRender, int SelectionVariable);

	void PopulateBigButton();

	void PopulateChoiceOutlineBox();

	~Menus();


};


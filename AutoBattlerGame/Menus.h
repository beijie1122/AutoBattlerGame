#pragma once
#include "Renderer.h"
#include "Node.h"
#include"LLNodeOperations.h"
#include <vector>
#include <string>
#include <Windows.h>

class Menus
{
public:

	int BigButtonHorizontalMeasure = 30;

	unsigned int BigButtonVerticleMeasure = 5;

	int ChoiceOutlineHorizontalMeasure = BigButtonHorizontalMeasure + 4;

	unsigned int ChoiceOutlineVerticleMeasure = BigButtonVerticleMeasure + 2;

	std::vector<std::vector<char>> BigButttonLayout{ BigButtonVerticleMeasure, std::vector<char>(BigButtonHorizontalMeasure) };

	std::vector<std::vector<char>> ChoiceOutlineLayout{ ChoiceOutlineVerticleMeasure, std::vector<char>(ChoiceOutlineHorizontalMeasure) };

	std::vector<std::string> MenuButtonText = { "Start Battle", "View Cards", "View Bestiary" };
	
	std::string FunctionalText = "Press W to move up, Press S to move down";

	std::vector<int> MenuRenderYCoords{ 5, 11, 17 };

	std::vector<int> TESTXCoordVec{ 5, 12, 19, 26 };

	int MenuRenderXCoord = 30;

	Menus();

	void MainGameMenu(Renderer MenuRender, int SelectionVariable);

	void PopulateBigButton();

	void PopulateChoiceOutlineBox();

	void Player1WinsMenu();

	void Player2WinsMenu();

	~Menus();


};


#pragma once

#include "Renderer.h"
#include "Node.h"
#include"LLNodeOperations.h"
#include <vector>
#include <string>
#include <Windows.h>
#include "CombatDataHandler.h"

class Menus
{
public:

	int BigButtonHorizontalMeasure = 30;

	unsigned int BigButtonVerticleMeasure = 5;

	int ChoiceOutlineHorizontalMeasure = BigButtonHorizontalMeasure + 4;

	unsigned int ChoiceOutlineVerticleMeasure = BigButtonVerticleMeasure + 2;

	unsigned int CardChoiceOutlineVerticleMeasure = 8;

	int CardChoiceOutlineHorizontalMeasure = 8;

	std::vector<std::vector<char>> BigButttonLayout{ BigButtonVerticleMeasure, std::vector<char>(BigButtonHorizontalMeasure) };

	std::vector<std::vector<char>> ChoiceOutlineLayout{ ChoiceOutlineVerticleMeasure, std::vector<char>(ChoiceOutlineHorizontalMeasure) };

	std::vector < std::vector<char>> CardChoiceOutlineLayout{ CardChoiceOutlineVerticleMeasure, std::vector<char>(CardChoiceOutlineHorizontalMeasure) };

	std::vector<std::string> MenuButtonText = { "Battle", "Deck Builder", "Bestiary NOT AVAILABLE" };
	
	//Put into a vector to read out of in the futures

	std::string FunctionalText = "Press W to move up, Press S to move down";

	std::string SelectionText = "Press 2 to make a selection";

	std::vector<int> MenuRenderYCoords{ 5, 11, 17 };

	std::vector<int> TESTXCoordVec{ 5, 12, 19, 26 };

	int MenuRenderXCoord = 30;

	//Setup for Printing Different Menus with the PrintMenu Function


	Menus();

	void PopulateBigButton();

	void PopulateChoiceOutlineBox();

	void PopulateCardChoiceOutlineBox();

	virtual void PrintMenu(CombatDataHandler &DataHandler);

	~Menus();


};
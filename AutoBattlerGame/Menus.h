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

	unsigned int CardChoiceOutlineVerticleMeasure = 8;

	int CardChoiceOutlineHorizontalMeasure = 8;

	std::vector<std::vector<char>> BigButttonLayout{ BigButtonVerticleMeasure, std::vector<char>(BigButtonHorizontalMeasure) };

	std::vector<std::vector<char>> ChoiceOutlineLayout{ ChoiceOutlineVerticleMeasure, std::vector<char>(ChoiceOutlineHorizontalMeasure) };

	std::vector < std::vector<char>> CardChoiceOutlineLayout{ CardChoiceOutlineVerticleMeasure, std::vector<char>(CardChoiceOutlineHorizontalMeasure) };

	std::vector<std::string> MenuButtonText = { "Battle", "Owned Cards & Build Deck", "Bestiary" };

	std::vector<int> BestiaryXCOORDSVec{};

	std::vector<int> BestiaryYCOORDSVec{};
	

	//Put into a vector to read out of in the futures

	std::string FunctionalText = "Press W to move up, Press S to move down";

	std::string SelectionText = "Press 2 to make a selection";

	std::string CombatSelectionText = "Press 3 to start combat";

	std::string InitiateCombatText = "Press 4 to move along combat";

	std::string InitiateBestiaryText = "Bestiary";

	std::string CombatMenuFrontText = "Front";

	std::string CombatMenuBackText = "Back";

	std::string CombatMenuTargetText = "Target";

	std::string PreCombatMenuText = "Combat Setup";

	std::string CombatInitializedText = "Combat Started";

	std::vector<int> MenuRenderYCoords{ 5, 11, 17 };

	std::vector<int> TESTXCoordVec{ 5, 12, 19, 26 };

	int MenuRenderXCoord = 30;

	Menus();

	void MainGameMenu(Renderer MenuRender, int SelectionVariable);

	void PopulateBigButton();

	void PopulateChoiceOutlineBox();

	void PopulateCardChoiceOutlineBox();

	void Player1WinsMenu();

	void Player2WinsMenu();

	void StartCombatMenu(Renderer CombatMenuRender);

	void InitiateCombatMenu(Renderer InitiateCombatMenuRenderer);

	void InitiateBestiaryMenu(Renderer InitiateRendererMenu);

	void PrintBestiarySelection(Renderer PrintBestiarySelection);

	void GenerateVectorForBestiaryCoords(std::vector<int> XCOORDS, std::vector<int> YCOORDS);

	void CombatMenuFirstAndLastPreview(Renderer MenuRender, std::vector<int> XCOORDS, int YCOORDS);

	void CombatInitiatedMenu(Renderer MenuRender, std::vector<int> P1XCOORDS, std::vector<int> P2XCOORDS, int YCOORDS, int P1TargetVecLocation, int P2TargetVecLocation);

	~Menus();


};


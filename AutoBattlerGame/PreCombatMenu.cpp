#include "PreCombatMenu.h"

PreCombatMenu::PreCombatMenu()
{

}

void PreCombatMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue(CombatSelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });

	DataHandler.RenderObject.DrawStringValue(PreCombatMenuText, { 1, 1 });

	//Renders the first box with the "Front" text
	DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { XCoordVec.at(3) - 1, YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(CombatMenuFrontText, { XCoordVec.at(3) - 1, YCoord + 7 });

	DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { XCoordVec.at(0) - 1, YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(CombatMenuBackText, { XCoordVec.at(0) - 1, YCoord + 7 });

	//Performs Rendering for the P1 Deck for Preview 

	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		DataHandler.P1Deck.at(i).RenderNode(DataHandler.RenderObject, XCoordVec.at(i), YCoord);
	}

}

PreCombatMenu::~PreCombatMenu()
{

}

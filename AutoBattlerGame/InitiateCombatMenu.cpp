#include "InitiateCombatMenu.h"

InitiateCombatMenu::InitiateCombatMenu()
{

}

void InitiateCombatMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue(InitiateCombatText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });

	DataHandler.RenderObject.DrawStringValue(CombatInitializedText, { 1, 1 });

	//Draws P1 Card Target
	DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { DataHandler.XCoordVec.at(DataHandler.TargetingP1VecLocation) - 1, DataHandler.YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(CombatMenuTargetText, { DataHandler.XCoordVec.at(DataHandler.TargetingP1VecLocation) - 1, DataHandler.YCoord + 7 });

	DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { DataHandler.P2XCoordVec.at(DataHandler.TargetingP2VecLocation) - 1, DataHandler.YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(CombatMenuTargetText, { DataHandler.P2XCoordVec.at(DataHandler.TargetingP2VecLocation) - 1, DataHandler.YCoord + 7 });

	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		DataHandler.P1Deck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.XCoordVec.at(i), DataHandler.YCoord);
		DataHandler.P2Deck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.P2XCoordVec.at(i), DataHandler.YCoord);
	}


}

InitiateCombatMenu::~InitiateCombatMenu()
{

}

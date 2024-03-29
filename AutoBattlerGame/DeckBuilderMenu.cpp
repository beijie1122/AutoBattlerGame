#include "DeckBuilderMenu.h"

DeckBuilderMenu::DeckBuilderMenu()
{

}

void DeckBuilderMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue("Deck Builder", { 1, 1 });
	DataHandler.RenderObject.DrawStringValue("Cards Collected", { 5, 4 });
	DataHandler.RenderObject.DrawStringValue("Current Deck", { 52, 4 });

	if (DataHandler.IsDeckSelectedToEdit == false)
	{
		//Insert UI showing Deck Selected Menu
		DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { DataHandler.DeckBuilderTargetXCoordVec.at(DataHandler.DeckBuilderXCoordTarget), DataHandler.DeckBuilderTargetYCoord }
		, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	}
	else if (DataHandler.IsSwapingEnabled == true)
	{
		//Insert UI Showing we are Swapping
		DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { DataHandler.DeckBuilderTargetXCoordVec.at(DataHandler.DeckBuilderXCoordTarget), DataHandler.DeckBuilderTargetYCoord }
		, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	}
	else
	{
		//Insert UI showing We are Viewing P1 Deck
		DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { DataHandler.DeckBuilderP1DeckTargetXCoordVec.at(DataHandler.DeckBuilderP1DeckXCoordTarget), DataHandler.DeckBuilderTargetYCoord}
		, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	}
	

	for (size_t i = 0; i < DataHandler.P1DeckBuilderDeck.size(); i++)
	{
		DataHandler.P1DeckBuilderDeck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.DeckBuilderXCoordVec.at(i), DataHandler.YCoord);
	}
	
	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		DataHandler.P1Deck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.DeckBuilderP1DeckXCoordVec.at(i), DataHandler.YCoord);
	}

	for (size_t i = 0; i < MenuButtonDescription.size(); i++)
	{
		DataHandler.RenderObject.DrawStringValue(MenuButtonDescription.at(i), { XCoord, YCoordVector.at(i) });
	}

}

DeckBuilderMenu::~DeckBuilderMenu()
{
}

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
		DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { DataHandler.DeckBuilderTargetXCoordVec.at(DataHandler.DeckBuilderXCoordTarget), DataHandler.DeckBuilderTargetYCoord }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	}
	

	for (size_t i = 0; i < DataHandler.P1DeckBuilderDeck.size(); i++)
	{
		DataHandler.P1DeckBuilderDeck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.DeckBuilderXCoordVec.at(i), DataHandler.YCoord);
	}
	
	for (size_t i = 0; i < DataHandler.P1Deck.size(); i++)
	{
		DataHandler.P1Deck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.DeckBuilderP1DeckXCoordVec.at(i), DataHandler.YCoord);
	}

}

DeckBuilderMenu::~DeckBuilderMenu()
{
}

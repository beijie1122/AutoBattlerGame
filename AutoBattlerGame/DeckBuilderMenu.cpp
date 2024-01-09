#include "DeckBuilderMenu.h"

DeckBuilderMenu::DeckBuilderMenu()
{

}

void DeckBuilderMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue("Deck Builder", { 1, 1 });

	for (size_t i = 0; i < DataHandler.P1DeckBuilderDeck.size(); i++)
	{
		DataHandler.P1DeckBuilderDeck.at(i)->RenderNode(DataHandler.RenderObject, DataHandler.DeckBuilderXCoordVec.at(i), DataHandler.YCoord);
	}

}

DeckBuilderMenu::~DeckBuilderMenu()
{
}

#include "CardFactory.h"

CardFactory::CardFactory()
{

}

void CardFactory::CreateNewCard(VanillaCards* InputCard, CombatDataHandler& DataHandler, int DeckSpot)
{
	DeckSpot--;

	if (InputCard->CardType == "Vanilla")
	{
		VanillaCards* NewCard = new VanillaCards(InputCard->Health, InputCard->Attack, InputCard->Name, InputCard->CardType);
		DataHandler.P1Deck.erase(DataHandler.P1Deck.begin() + DeckSpot);
		DataHandler.P1Deck.at(DeckSpot) = NewCard;
	}

	else if (InputCard->CardType == "Sniper")
	{
		SniperCard* NewCard = new SniperCard(InputCard->Health, InputCard->Attack, InputCard->Name, InputCard->CardType);
		DataHandler.P1Deck.erase(DataHandler.P1Deck.begin() + DeckSpot);
		DataHandler.P1Deck.at(DeckSpot) = NewCard;
	}

}

CardFactory::~CardFactory()
{
}

#include "CardFactory.h"

CardFactory::CardFactory()
{

}

void CardFactory::CreateNewCard(VanillaCards* InputCard, std::vector<VanillaCards*>& Deck, int& DeckSpot)
{
	//DeckSpot--;

	if (InputCard->CardType == "Vanilla")
	{
		VanillaCards* NewCard = new VanillaCards(InputCard->Health, InputCard->Attack, InputCard->Name, InputCard->CardType);
		Deck.push_back(NewCard);
		std::iter_swap(Deck.begin() + DeckSpot, Deck.end() - 1);
		Deck.erase(Deck.end() - 1);
		//Check HERE
	}

	else if (InputCard->CardType == "Sniper")
	{
		SniperCard* NewCard = new SniperCard(InputCard->Health, InputCard->Attack, InputCard->Name, InputCard->CardType);
		Deck.push_back(NewCard);
		std::iter_swap(Deck.begin() + DeckSpot, Deck.end() - 1);
		Deck.erase(Deck.end() - 1);
	}

}

CardFactory::~CardFactory()
{
}

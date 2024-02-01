#include "CardFactory.h"

CardFactory::CardFactory()
{

}

void CardFactory::CreateDummyDeck(CardHolder& P1Deck)
{
	for (size_t i = 0; i < 4; i++)
	{
		VanillaCards* NewCard = new VanillaCards(0, 0, "BLANK", "BLANK");
		P1Deck.Holder.push_back(NewCard);
	}
}

void CardFactory::CreateDummyAllCardsHolder(CardHolder& AllCardsHolder, std::vector<int> HPVec)
{
	for (size_t i = 0; i < HPVec.size(); i++)
	{
		VanillaCards* NewCard = new VanillaCards(0, 0, "BLANK", "BLANK");
		AllCardsHolder.Holder.push_back(NewCard);
	}
}

void CardFactory::CreateAllCardsHolder(CardHolder& AllCardsHolder, std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec, std::vector<std::string> TypeVec)
{
	for (size_t i = 0; i < HPVec.size(); i++)
	{
		VanillaCards* NewCard = new VanillaCards(HPVec.at(i), ATTVec.at(i), NameVec.at(i), TypeVec.at(i));
		CreateNewCard(NewCard, AllCardsHolder.Holder, i);
	}
}

void CardFactory::CreateDummyDeckBuilderDeck(std::vector<VanillaCards*>& DeckBuilderDeck, CardHolder AllCards)
{
	//Have to make considerations for adding cards to the P1 Deck
	for (size_t i = 0; i < 5; i++)
	{
		VanillaCards* NewCard = new VanillaCards(0, 0, "BLANK", "BLANK");
		DeckBuilderDeck.push_back(NewCard);
	}
	CreateDeckBuilderDeck(DeckBuilderDeck, AllCards);

}

void CardFactory::CreateDeckBuilderDeck(std::vector<VanillaCards*>& DeckBuilderDeck, CardHolder AllCards)
{
	for (size_t i = 0; i < 5; i++)
	{
		CreateNewCard(AllCards.Holder.at(i), DeckBuilderDeck, i);
	}
	//Making Sniper in P1 Base Deck
	CreateNewCard(AllCards.Holder.at(10), DeckBuilderDeck, 0);
}

void CardFactory::CreateP1StartingDeck(CardHolder& P1Deck, CardHolder CardContainer)
{
	for (int i = 0; i < 4; i++)
	{
		CreateNewCard(CardContainer.Holder.at(i), P1Deck.Holder, i);
	}

	//Making Sniper in P1 Base Deck
	CreateNewCard(CardContainer.Holder.at(10), P1Deck.Holder, 0);

}


void CardFactory::CreateNewCard(VanillaCards* InputCard, std::vector<VanillaCards*>& Deck, int DeckSpot)
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

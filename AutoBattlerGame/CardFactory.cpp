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

void CardFactory::CreateDummyP2Deck(CardHolder& P2Deck, CardHolder AllCards)
{
	for (size_t i = 0; i < 4; i++)
	{
		VanillaCards* NewCard = new VanillaCards(0, 0, "BLANK", "BLANK");
		P2Deck.Holder.push_back(NewCard);
	}
	CreateP2Deck(P2Deck, AllCards);
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

void CardFactory::CreateP2Deck(CardHolder& P2Deck, CardHolder AllCards)
{
	int RandomNumber;

	for (size_t i = 0; i < 4; i++)
	{
		RandomNumber = RandomNumberGenerator(MinValueForNumGen, AllCards.Holder.size() - 1);
		VanillaCards* NewCard = new VanillaCards(AllCards.Holder.at(RandomNumber)->Health, AllCards.Holder.at(RandomNumber)->Attack,
			AllCards.Holder.at(RandomNumber)->Name, AllCards.Holder.at(RandomNumber)->CardType);
		CreateNewCard(NewCard, P2Deck.Holder, i);
	}
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

void CardFactory::CreateStoredDummyDecks(CombatDataHandler& DataHandler)
{
	if (DataHandler.P1StoredDeck.size() == 0)
	{
		for (size_t i = 0; i < 4; i++)
		{
			VanillaCards* NewCard = new VanillaCards(0, 0, "BLANK", "BLANK");
			DataHandler.P1StoredDeck.push_back(NewCard);
			DataHandler.P2StoredDeck.push_back(NewCard);
		}
	}
}

void CardFactory::CopyDecksToStoredDecks(CardHolder P1Deck, CardHolder P2Deck, CombatDataHandler& DataHandler)
{
	for (size_t i = 0; i < 4; i++)
	{
		CreateNewCard(DataHandler.P1Deck.at(i), DataHandler.P1StoredDeck, i);
		CreateNewCard(DataHandler.P2Deck.at(i), DataHandler.P2StoredDeck, i);
	}
}

void CardFactory::ResetDecksForDataHandler(CombatDataHandler& DataHandler)
{
	for (size_t i = 0; i < 4; i++)
	{
		CreateNewCard(DataHandler.P1StoredDeck.at(i), DataHandler.P1Deck, i);
		CreateNewCard(DataHandler.P2StoredDeck.at(i), DataHandler.P2Deck, i);
	}
}

int CardFactory::RandomNumberGenerator(int Min, int Max)
{
	int RandomVariable;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(Min, Max);

	RandomVariable = distrib(gen);

	return RandomVariable;
}

CardFactory::~CardFactory()
{
}

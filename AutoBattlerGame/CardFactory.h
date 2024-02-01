#pragma once
#include "VanillaCards.h"
#include "SniperCard.h"
#include "CombatDataHandler.h"
#include "CardHolder.h"
#include <vector>
#include <algorithm>

class CardHolder;

class CardFactory
{
public:

	CardFactory();

	void CreateDummyDeck(CardHolder& P1Deck);

	void CreateDummyAllCardsHolder(CardHolder& AllCardsHolder, std::vector<int> HPVec);

	void CreateDummyDeckBuilderDeck(std::vector<VanillaCards*>& DeckBuilderDeck, CardHolder AllCards);

	void CreateAllCardsHolder(CardHolder& AllCardsHolder, std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec,
		std::vector<std::string> TypeVec);

	void CreateDeckBuilderDeck(std::vector<VanillaCards*>& DeckBuilderDeck, CardHolder AllCards);

	void CreateP1StartingDeck(CardHolder& P1Deck, CardHolder CardContainer);

	void CreateNewCard(VanillaCards* InputCard, std::vector<VanillaCards*>& Deck, int DeckSpot);

	~CardFactory();
};


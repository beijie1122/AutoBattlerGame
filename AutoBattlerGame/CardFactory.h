#pragma once
#include "VanillaCards.h"
#include "SniperCard.h"
#include "CombatDataHandler.h"
#include "CardHolder.h"
#include <vector>
#include <algorithm>
#include <random>

class CardHolder;

class CardFactory
{

	int MinValueForNumGen = 0;

public:

	CardFactory();

	void CreateDummyDeck(CardHolder& P1Deck);

	void CreateDummyAllCardsHolder(CardHolder& AllCardsHolder, std::vector<int> HPVec);

	void CreateDummyDeckBuilderDeck(std::vector<VanillaCards*>& DeckBuilderDeck, CardHolder AllCards);

	void CreateDummyP2Deck(CardHolder& P2Deck, CardHolder AllCards);

	void CreateAllCardsHolder(CardHolder& AllCardsHolder, std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec,
		std::vector<std::string> TypeVec);

	void CreateDeckBuilderDeck(std::vector<VanillaCards*>& DeckBuilderDeck, CardHolder AllCards);

	void CreateP1StartingDeck(CardHolder& P1Deck, CardHolder CardContainer);

	void CreateP2Deck(CardHolder& P2Deck, CardHolder AllCards);

	void CreateNewCard(VanillaCards* InputCard, std::vector<VanillaCards*>& Deck, int DeckSpot);

	int RandomNumberGenerator(int Min, int Max);

	~CardFactory();
};


#pragma once
#include "VanillaCards.h"
#include "SniperCard.h"
#include "CombatDataHandler.h"
#include <vector>
#include <algorithm>


class CardFactory
{
public:

	CardFactory();

	void CreateNewCard(VanillaCards* InputCard, std::vector<VanillaCards*>& Deck, int& DeckSpot);

	~CardFactory();
};


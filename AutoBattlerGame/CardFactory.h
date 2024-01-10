#pragma once
#include "VanillaCards.h"
#include "SniperCard.h"
#include "CombatDataHandler.h"
#include <vector>


class CardFactory
{
public:

	CardFactory();

	void CreateNewCard(VanillaCards* InputCard, CombatDataHandler& DataHandler, int DeckSpot);

	~CardFactory();
};


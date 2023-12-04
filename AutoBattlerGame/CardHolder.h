#pragma once
#include<vector>
#include<string>
#include"VanillaCards.h"
#include <random>
#include "SniperCard.h"

class CardHolder
{

public:

	std::vector<VanillaCards*> Holder;

	int MinValueforNumGenerator = 0;

	int MaxValueforNumGenerator = 9;

	CardHolder();

	CardHolder(std::string PlayerInput, CardHolder AllCards);

	void PopulateAllCardsVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec);

	void PopulatePlayer1BaseDeck(CardHolder AllCards);

	int RandomNumberGenerator(int Min, int Max);

	~CardHolder();
};


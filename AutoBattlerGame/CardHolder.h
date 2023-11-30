#pragma once
#include<vector>
#include<string>
#include"VanillaCards.h"

class CardHolder
{

public:

	std::vector<VanillaCards> Holder;

	CardHolder();

	void PopulateAllCardsVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec);

	~CardHolder();
};


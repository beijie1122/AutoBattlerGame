#include "CardHolder.h"

CardHolder::CardHolder()
{

}

CardHolder::CardHolder(std::string PlayerInput, CardHolder AllCards)
{
	if (PlayerInput == "Player2Deck")
	{
		int RandomNumber;

		for (size_t i = 0; i < 4; i++)
		{
			RandomNumber = RandomNumberGenerator(MinValueforNumGenerator, MaxValueforNumGenerator);
			VanillaCards NewCard(AllCards.Holder.at(RandomNumber).Health, AllCards.Holder.at(RandomNumber).Attack, AllCards.Holder.at(RandomNumber).Name);
			this->Holder.push_back(NewCard);
		}
	}
}

void CardHolder::PopulateAllCardsVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec)
{
	for (size_t i = 0; i < HPVec.size(); i++)
	{
		std::string CardName = NameVec.at(i);
		VanillaCards NewCard(HPVec.at(i), ATTVec.at(i), NameVec.at(i));
		Holder.push_back(NewCard);
	}
}

void CardHolder::PopulatePlayer1BaseDeck(CardHolder AllCards)
{
	for (size_t i = 0; i < 4; i++)
	{
		VanillaCards NewCard(AllCards.Holder.at(i).Health, AllCards.Holder.at(i).Attack, AllCards.Holder.at(i).Name);
		this->Holder.push_back(NewCard);
	}
}

int CardHolder::RandomNumberGenerator(int Min, int Max)
{
	int RandomVariable;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(Min, Max);

	RandomVariable = distrib(gen);

	return RandomVariable;
}

CardHolder::~CardHolder()
{

}

#include "CardHolder.h"

CardHolder::CardHolder()
{

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

CardHolder::~CardHolder()
{

}

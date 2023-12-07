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
			//Generating Sniper Card in opponent deck is bugged, thus adding -1 to size
			RandomNumber = RandomNumberGenerator(MinValueforNumGenerator, AllCards.Holder.size() - 1);
			if (AllCards.Holder.at(RandomNumber)->CardType == "Vanilla")
			{
				VanillaCards* NewCard = new VanillaCards(AllCards.Holder.at(RandomNumber)->Health, AllCards.Holder.at(RandomNumber)->Attack, AllCards.Holder.at(RandomNumber)->Name, AllCards.Holder.at(RandomNumber)->CardType);
				this->Holder.push_back(NewCard);
			}
			else if (AllCards.Holder.at(RandomNumber)->CardType == "Sniper")
			{
				//SniperCard* NewCard = new SniperCard(AllCards.Holder.at(RandomNumber)->Health, AllCards.Holder.at(RandomNumber)->Attack, AllCards.Holder.at(RandomNumber)->Name, AllCards.Holder.at(RandomNumber)->CardType);
				SniperCard* NewCard = new SniperCard();
				this->Holder.push_back(NewCard);
			}
			
			
		}
	}
}

void CardHolder::PopulateAllCardsVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec, std::vector<std::string> CardTypeVec)
{
	for (size_t i = 0; i < HPVec.size(); i++)
	{
		std::string CardName = NameVec.at(i);
		if (CardTypeVec.at(i) == "Vanilla")
		{
			VanillaCards* NewCard = new VanillaCards(HPVec.at(i), ATTVec.at(i), NameVec.at(i), CardTypeVec.at(i));
			Holder.push_back(NewCard);
		}
		else if (CardTypeVec.at(i) == "Sniper")
		{
			SniperCard* NewCard = new SniperCard(HPVec.at(i), ATTVec.at(i), NameVec.at(i), CardTypeVec.at(i));
			Holder.push_back(NewCard);
		}
	}
}

void CardHolder::PopulatePlayer1BaseDeck(CardHolder AllCards)
{
	for (size_t i = 0; i < 4; i++)
	{
		VanillaCards* NewCard = new VanillaCards(AllCards.Holder.at(i)->Health, AllCards.Holder.at(i)->Attack, AllCards.Holder.at(i)->Name, AllCards.Holder.at(i)->CardType);
		this->Holder.push_back(NewCard);
	}

	SniperCard* NewSniper = new SniperCard();
	this->Holder[0] = NewSniper;
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

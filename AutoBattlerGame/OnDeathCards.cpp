#include "OnDeathCards.h"

OnDeathCards::OnDeathCards()
{

}

OnDeathCards::OnDeathCards(int HP, int ATT, std::string NamePassed, std::string Type)
{
	this->Health = HP;
	this->Attack = ATT;
	this->Name = NamePassed;
	this->NameAbrFirstLetter = NamePassed.at(0);
	this->NameAbrSecondLetter = NamePassed.at(1);
	this->NameAbrThirdLetter = NamePassed.at(2);
	this->NameAbrFourthLetter = NamePassed.at(3);
	this->CardType = Type;
	this->SetupCardLayout();
}

void OnDeathCards::OnDeathEffect(CombatDataHandler& DataHandler, std::string Owner)
{
	VanillaCards* NewCard = new VanillaCards(1, 1, "Gugu", "Vanilla");
	
	if (Owner == "P1")
	{
		DataHandler.Factory->CreateNewCard(NewCard, DataHandler.P1Deck, DataHandler.TargetingP1VecLocation);
	}
	else if (Owner == "P2")
	{
		DataHandler.Factory->CreateNewCard(NewCard, DataHandler.P2Deck, DataHandler.TargetingP2VecLocation);
	}
}

OnDeathCards::~OnDeathCards()
{

}

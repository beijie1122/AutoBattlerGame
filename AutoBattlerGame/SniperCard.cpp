#include "SniperCard.h"

class CombatDataHandler;

SniperCard::SniperCard()
{
	this->DoesCardHavePreCombatAbility = true;
	this->Health = 2;
	this->Attack = 2;
	this->Name = "Sniper";
	this->NameAbrFirstLetter = Name[0];
	this->NameAbrSecondLetter = Name[1];
	this->NameAbrThirdLetter = Name[2];
	this->NameAbrFourthLetter = Name[3];
	this->CardType = SniperType;
	this->SetupCardLayout();

}

SniperCard::SniperCard(int HP, int ATT, std::string NamePassed)
{
	this->Health = HP;
	this->Attack = ATT;
	this->Name = NamePassed;
	this->DoesCardHavePreCombatAbility = true;
	this->NameAbrFirstLetter = Name[0];
	this->NameAbrSecondLetter = Name[1];
	this->NameAbrThirdLetter = Name[2];
	this->NameAbrFourthLetter = Name[3];
	this->CardType = SniperType;
	this->SetupCardLayout();
}


void SniperCard::PreCombatAbility(CombatDataHandler& DataHandler, std::string Owner)
{
	if (Owner == "P1")
	{
		DataHandler.P2Deck.at(3)->Health = DataHandler.P2Deck.at(3)->Health - this->Attack;
	}
	if (Owner == "P2")
	{
		DataHandler.P1Deck.at(0)->Health = DataHandler.P1Deck.at(0)->Health - this->Attack;
	}
}

SniperCard::~SniperCard()
{

}



#include "Broadcaster.h"

Broadcaster::Broadcaster()
{
	this->CardsDefeatedAmt = 0;
	this->DamageDealtAmt = 0;
	this->WinGameAmt = 0;
}

void Broadcaster::ResetAllValues()
{
	this->CardsDefeatedAmt = 0;
	this->DamageDealtAmt = 0;
	//this->WinGameAmt = 0;
}

void Broadcaster::IncrementCardsDefeatedAmt()
{
	this->CardsDefeatedAmt++;
}

void Broadcaster::IncrementDamageDeltAmt(int Damage)
{
	this->DamageDealtAmt+= Damage;
}

void Broadcaster::IncrementWinGameAmt()
{
	this->WinGameAmt++;
}

Broadcaster::~Broadcaster()
{

}

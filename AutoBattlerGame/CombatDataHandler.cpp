#include "CombatDataHandler.h"

CombatDataHandler::CombatDataHandler()
{
	this->TargetingP1VecLocation = 3;
	this->TargetingP2VecLocation = 0;
}

void CombatDataHandler::GenerateNewP2Deck(CardHolder AllCards)
{
	CardHolder NewP2Deck("Player2Deck", AllCards);
}

void CombatDataHandler::EstablishStoredDecks()
{
	for (size_t i = 0; i < P1Deck.size(); i++)
	{
		VanillaCards* NewCard = new VanillaCards(P1Deck.at(i)->Health, P1Deck.at(i)->Attack, P1Deck.at(i)->Name);
		if (P1StoredDeck.size() < 4)
		{
			P1StoredDeck.push_back(NewCard);
		}
		else
		{
			P1StoredDeck.at(i) = NewCard;
		}
	}

	for (size_t i = 0; i < P2Deck.size(); i++)
	{
		VanillaCards* NewCard2 = new VanillaCards(P2Deck.at(i)->Health, P2Deck.at(i)->Attack, P2Deck.at(i)->Name);
		if (P2StoredDeck.size() < 4)
		{
			P2StoredDeck.push_back(NewCard2);
		}
		else
		{
			P2StoredDeck.at(i) = NewCard2;
		}
	}
}

void CombatDataHandler::ResetDecks()
{
	for (size_t i = 0; i < P1Deck.size(); i++)
	{
		delete P1Deck.at(i);
		delete P2Deck.at(i);
	}
	for (size_t j = 0; j < P1Deck.size(); j++)
	{
		VanillaCards* NewCard = new VanillaCards(P1StoredDeck.at(j)->Health, P1StoredDeck.at(j)->Attack, P1StoredDeck.at(j)->Name);
		P1Deck[j] = NewCard;
		delete P1StoredDeck[j];

		VanillaCards* NewCard2 = new VanillaCards(P2StoredDeck.at(j)->Health, P2StoredDeck.at(j)->Attack, P2StoredDeck.at(j)->Name);
		P2Deck[j] = NewCard2;
		delete P2StoredDeck[j];
	}

}

void CombatDataHandler::PostCombatValueReset()
{
	ResetDecks();
	this->TargetingP1VecLocation = 3;
	this->TargetingP2VecLocation = 0;
	this->IsCombatFinished = false;
	this->IsCombatSetup = false;
	this->Player1Wins = false;
	this->Player2Wins = false;
}

CombatDataHandler::~CombatDataHandler()
{

}

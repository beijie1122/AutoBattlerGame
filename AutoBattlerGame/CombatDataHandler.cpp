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
	P1StoredDeck = P1Deck;
	P2StoredDeck = P2Deck;
}

void CombatDataHandler::ResetDecks()
{
	P1Deck = P1StoredDeck;
	P2Deck = P2StoredDeck;
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

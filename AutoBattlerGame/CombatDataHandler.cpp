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

void CombatDataHandler::PushbackCardsforStoredDecks(std::vector<VanillaCards*> &StorageVec, VanillaCards* CardToBeStored, int i)
{
	if (StorageVec.size() < 4)
	{
		StorageVec.push_back(CardToBeStored);
	}
	else
	{
		StorageVec.at(i) = CardToBeStored;
	}
}

void CombatDataHandler::EstablishStoredDecks()
{
	for (size_t i = 0; i < P1Deck.size(); i++)
	{
		if (P1Deck.at(i)->CardType == "Vanilla")
		{
			VanillaCards* NewCard = new VanillaCards(P1Deck.at(i)->Health, P1Deck.at(i)->Attack, P1Deck.at(i)->Name, P1Deck.at(i)->CardType);
			PushbackCardsforStoredDecks(P1StoredDeck, NewCard, i);
		}
		else
		{
			SniperCard* NewCard = new SniperCard(P1Deck.at(i)->Health, P1Deck.at(i)->Attack, P1Deck.at(i)->Name, P1Deck.at(i)->CardType);
			PushbackCardsforStoredDecks(P1StoredDeck, NewCard, i);
		}
	}

	for (size_t i = 0; i < P2Deck.size(); i++)
	{
		if (P2Deck.at(i)->CardType == "Vanilla")
		{
			VanillaCards* NewCard = new VanillaCards(P2Deck.at(i)->Health, P2Deck.at(i)->Attack, P2Deck.at(i)->Name, P2Deck.at(i)->CardType);
			PushbackCardsforStoredDecks(P2StoredDeck, NewCard, i);
		}
		else
		{
			SniperCard* NewCard = new SniperCard(P2Deck.at(i)->Health, P2Deck.at(i)->Attack, P2Deck.at(i)->Name, P2Deck.at(i)->CardType);
			PushbackCardsforStoredDecks(P2StoredDeck, NewCard, i);
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
		if (P1StoredDeck.at(j)->CardType == "Vanilla")
		{
			VanillaCards* NewCard = new VanillaCards(P1StoredDeck.at(j)->Health, P1StoredDeck.at(j)->Attack, 
				P1StoredDeck.at(j)->Name, P1StoredDeck.at(j)->CardType);
			ResetDecksAssistingFunctinon(P1Deck, NewCard, j);
		}
		else if (P1StoredDeck.at(j)->CardType == "Sniper")
		{
			SniperCard* NewCard = new SniperCard(P1StoredDeck.at(j)->Health, P1StoredDeck.at(j)->Attack, 
				P1StoredDeck.at(j)->Name, P1StoredDeck.at(j)->CardType);
			ResetDecksAssistingFunctinon(P1Deck, NewCard, j);
		}
		delete P1StoredDeck[j];


		if (P2StoredDeck.at(j)->CardType == "Vanilla")
		{
			VanillaCards* NewCard2 = new VanillaCards(P2StoredDeck.at(j)->Health, P2StoredDeck.at(j)->Attack, 
				P2StoredDeck.at(j)->Name, P2StoredDeck.at(j)->CardType);
			ResetDecksAssistingFunctinon(P2Deck, NewCard2, j);
		}
		else if (P2StoredDeck.at(j)->CardType == "Sniper")
		{
			SniperCard* NewCard2 = new SniperCard(P2StoredDeck.at(j)->Health, P2StoredDeck.at(j)->Attack, 
				P2StoredDeck.at(j)->Name, P2StoredDeck.at(j)->CardType);
			ResetDecksAssistingFunctinon(P2Deck, NewCard2, j);
		}
		delete P2StoredDeck[j];

	}

}

void CombatDataHandler::ResetDecksAssistingFunctinon(std::vector<VanillaCards*>& StorageVec, VanillaCards* CardToBeStored, int j)
{
	StorageVec[j] = CardToBeStored;
}

void CombatDataHandler::PopulateStartGameP1Deck(CardHolder AllCards)
{
	for (size_t i = 0; i < 4; i++)
	{
		VanillaCards* NewCard = new VanillaCards(AllCards.Holder.at(i)->Health, AllCards.Holder.at(i)->Attack, AllCards.Holder.at(i)->Name, AllCards.Holder.at(i)->CardType);
		this->P1DeckBuilderDeck.push_back(NewCard);
	}

	SniperCard* NewSniper = new SniperCard();
	this->P1DeckBuilderDeck.push_back(NewSniper);
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
	this->CombatResultsInADraw = false;
}

void CombatDataHandler::Player2WinsCombat()
{
	this->Player2Wins = true;
	this->IsCombatFinished = true;
}

void CombatDataHandler::Player1WinsCombat()
{
	this->Player1Wins = true;
	this->IsCombatFinished = true;
}

void CombatDataHandler::CombatIsADraw()
{
	this->CombatResultsInADraw = true;
	this->IsCombatFinished = true;
}

void CombatDataHandler::AdvanceP1TargetVecLocation()
{
	this->TargetingP1VecLocation--;
}

void CombatDataHandler::AdvanceP2TargetVecLocation()
{
	this->TargetingP2VecLocation++;
}

void CombatDataHandler::CombatAlreadySetup()
{
	this->TargetingP1VecLocation = 3;
	this->TargetingP2VecLocation = 0;
	this->IsCombatSetup = true;
}

void CombatDataHandler::IncreaseTargetValue()
{
	if (IsDeckSelectedToEdit == false)
	{
		DeckBuilderIncreaseTarget(DeckBuilderXCoordTarget, DeckBuilderXCoordMax);
	}
	else
	{
		DeckBuilderIncreaseTarget(DeckBuilderP1DeckXCoordTarget, DeckBuilderP1DeckXCoordMax);
	}
}

void CombatDataHandler::DecreaseTargetValue()
{
	if (IsDeckSelectedToEdit == false)
	{
		DeckBuilderDecreaseTarget(DeckBuilderXCoordTarget, DeckBuilderXCoordMax);
	}
	else
	{
		DeckBuilderDecreaseTarget(DeckBuilderP1DeckXCoordTarget, DeckBuilderP1DeckXCoordMax);
	}
}

void CombatDataHandler::DeckBuilderIncreaseTarget(int &VecToIncrease, int IncreaseVecMaxValue)
{
	if (VecToIncrease < IncreaseVecMaxValue)
	{
		VecToIncrease++;
	}
	else
	{
		VecToIncrease = 0;
	}
}

void CombatDataHandler::DeckBuilderDecreaseTarget(int &VectoDecrease, int DecreaseVecMaxValue)
{
	if (VectoDecrease != 0)
	{
		VectoDecrease--;
	}
	else
	{
		VectoDecrease = DecreaseVecMaxValue;
	}
}

void CombatDataHandler::ChangeEdit()
{
	if (this->IsDeckSelectedToEdit == false)
	{
		this->IsDeckSelectedToEdit = true;
	}
	else
	{
		this->IsDeckSelectedToEdit = false;
	}
}


CombatDataHandler::~CombatDataHandler()
{

}

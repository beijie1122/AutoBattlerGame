#include "DefeatCardsQuest.h"

DefeatCardsQuest::DefeatCardsQuest()
{
	this->ObjectiveText = "Defeat 6 of your opponent's Cards!";
	this->QuestName = "Defeat the Cards!";
	this->CurrentAmt = 0;
	this->GoalAmt = 6;
	this->QuestType = "DefeatOpponentCards";
}

DefeatCardsQuest::~DefeatCardsQuest()
{

}

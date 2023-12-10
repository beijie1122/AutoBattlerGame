#include "Listener.h"

Listener::Listener()
{
	DefeatCardsQuest* NewQuest = new DefeatCardsQuest();

	this->QuestsStorageVector.push_back(NewQuest);
}

void Listener::UpdateForDefeatCardsQuests(Broadcaster* BroadcasterObj)
{
	for (size_t i = 0; i < this->QuestsStorageVector.size(); i++)
	{
		if (this->QuestsStorageVector.at(i)->QuestType == "DefeatOpponentCards")
		{
			this->QuestsStorageVector.at(i)->CurrentAmt += BroadcasterObj->CardsDefeatedAmt;
		}
	}

	CheckIfQuestsAreCompleted();
}

void Listener::CheckIfQuestsAreCompleted()
{
	for (size_t i = 0; i < this->QuestsStorageVector.size(); i++)
	{
		this->QuestsStorageVector.at(i)->QuestComplete();
	}
}

Listener::~Listener()
{

}

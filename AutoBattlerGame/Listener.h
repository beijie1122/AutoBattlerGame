#pragma once
#include "QuestsBaseClass.h"
#include "DefeatCardsQuest.h"
#include "Broadcaster.h"
#include <vector>
class Listener
{
public:
	std::vector<QuestsBaseClass*> QuestsStorageVector;

	int XCOORD; 

	std::vector<int> YCOORDVEC;

	Listener();

	void UpdateForDefeatCardsQuests(Broadcaster* BroadcasterObj);

	void CheckIfQuestsAreCompleted();

	~Listener();
};


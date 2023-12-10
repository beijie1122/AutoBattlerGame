#pragma once
#include <string>
#include "Renderer.h"
class QuestsBaseClass
{
public:

	int CurrentAmt;

	int GoalAmt;

	std::string QuestName;

	std::string ObjectiveText;

	std::string QuestType;

	bool IsQuestCompleted = false;

	QuestsBaseClass();

	virtual void IncrementGoalAmt();

	virtual void QuestComplete();

	virtual void PrintQuestInfo(Renderer* RenderQuad, int XCOORD, int YCOORD);

	~QuestsBaseClass();
};


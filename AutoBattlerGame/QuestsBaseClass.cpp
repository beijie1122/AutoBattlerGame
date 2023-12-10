#include "QuestsBaseClass.h"

QuestsBaseClass::QuestsBaseClass()
{

}

void QuestsBaseClass::IncrementGoalAmt()
{
	this->CurrentAmt++;
}

void QuestsBaseClass::QuestComplete()
{
	if (CurrentAmt >= GoalAmt)
	{
		this->ObjectiveText = "QUEST COMPLETED!";
		this->IsQuestCompleted = true;
		//Something that shows quest complete
	}
}

void QuestsBaseClass::PrintQuestInfo(Renderer* RenderQuad, int XCOORD, int YCOORD)
{
	int LineLength = this->QuestName.size() + 2;
	int SecondLineLength = this->QuestName.size() + 5;

	if (this->IsQuestCompleted != true)
	{
		RenderQuad->DrawStringValue(this->QuestName, { XCOORD, YCOORD });
		RenderQuad->DrawCardIntValue(this->CurrentAmt, { XCOORD + LineLength, YCOORD });
		RenderQuad->DrawCardIntValue(this->GoalAmt, { XCOORD + SecondLineLength, YCOORD });
	}
	else
	{
		RenderQuad->DrawStringValue(this->QuestName, { XCOORD, YCOORD });
		RenderQuad->DrawStringValue(this->ObjectiveText, { XCOORD + LineLength, YCOORD });
	}


}

QuestsBaseClass::~QuestsBaseClass()
{

}

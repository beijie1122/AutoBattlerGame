#include "PreCombatMenu.h"

PreCombatMenu::PreCombatMenu()
{

}

void PreCombatMenu::PrintMenu(Renderer MenuRender, int SelectionVariable)
{
	MenuRender.DrawStringValue(CombatSelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });

	MenuRender.DrawStringValue(PreCombatMenuText, { 1, 1 });

	//Renders the first box with the "Front" text
	MenuRender.DrawCardVector(CardChoiceOutlineLayout, { XCoordVec.at(3) - 1, YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	MenuRender.DrawStringValue(CombatMenuFrontText, { XCoordVec.at(3) - 1, YCoord + 7 });

	MenuRender.DrawCardVector(CardChoiceOutlineLayout, { XCoordVec.at(0) - 1, YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	MenuRender.DrawStringValue(CombatMenuBackText, { XCoordVec.at(0) - 1, YCoord + 7 });
}

void PreCombatMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawStringValue(CombatSelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });

	DataHandler.RenderObject.DrawStringValue(PreCombatMenuText, { 1, 1 });

	//Renders the first box with the "Front" text
	DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { XCoordVec.at(3) - 1, YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(CombatMenuFrontText, { XCoordVec.at(3) - 1, YCoord + 7 });

	DataHandler.RenderObject.DrawCardVector(CardChoiceOutlineLayout, { XCoordVec.at(0) - 1, YCoord - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(CombatMenuBackText, { XCoordVec.at(0) - 1, YCoord + 7 });
}

PreCombatMenu::~PreCombatMenu()
{

}

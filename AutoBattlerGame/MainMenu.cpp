#include "MainMenu.h"

MainMenu::MainMenu()
{

}

void MainMenu::PrintMenu(CombatDataHandler& DataHandler)
{
	DataHandler.RenderObject.DrawCardVector(ChoiceOutlineLayout, { MenuRenderXCoord - 2, MenuRenderYCoords.at(DataHandler.SelectionToBePassed) - 1 }, ChoiceOutlineVerticleMeasure, ChoiceOutlineHorizontalMeasure);
	DataHandler.RenderObject.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(0) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(MenuButtonText.at(0), { MenuRenderXCoord + 3, MenuRenderYCoords.at(0) + 2 });

	DataHandler.RenderObject.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(1) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(MenuButtonText.at(1), { MenuRenderXCoord + 3, MenuRenderYCoords.at(1) + 2 });

	DataHandler.RenderObject.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(2) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	DataHandler.RenderObject.DrawStringValue(MenuButtonText.at(2), { MenuRenderXCoord + 3, MenuRenderYCoords.at(2) + 2 });

	DataHandler.RenderObject.DrawStringValue(FunctionalText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 8 });

	DataHandler.RenderObject.DrawStringValue(SelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });
}

MainMenu::~MainMenu()
{
}

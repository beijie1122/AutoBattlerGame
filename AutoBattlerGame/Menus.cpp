#include "Menus.h"

Menus::Menus()
{
	this->PopulateBigButton();
	this->PopulateChoiceOutlineBox();
}

void Menus::MainGameMenu(Renderer MenuRender, int SelectionVariable) //Think about optimization via loops 
{
	//Must Put Overlay after the initial border object to Work
	MenuRender.DrawCardVector(ChoiceOutlineLayout, { MenuRenderXCoord - 2, MenuRenderYCoords.at(SelectionVariable) -1 }, ChoiceOutlineVerticleMeasure, ChoiceOutlineHorizontalMeasure);
	MenuRender.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(0) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	MenuRender.DrawStringValue(MenuButtonText.at(0), { MenuRenderXCoord + 3, MenuRenderYCoords.at(0) + 2 });

	MenuRender.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(1) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	MenuRender.DrawStringValue(MenuButtonText.at(1), { MenuRenderXCoord + 3, MenuRenderYCoords.at(1) + 2 });

	MenuRender.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(2) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	MenuRender.DrawStringValue(MenuButtonText.at(2), { MenuRenderXCoord + 3, MenuRenderYCoords.at(2) + 2 });

}

void Menus::PopulateBigButton()
{
	for (int i = 0; i < BigButtonVerticleMeasure; i++)
	{
		for (int j = 0; j < BigButtonHorizontalMeasure; j++)
		{
			if (i == 0 || i == BigButtonVerticleMeasure - 1)
			{
				BigButttonLayout[i][j] = 205;
			}
			else if(j == 0 || j == BigButtonHorizontalMeasure - 1)
			{
				BigButttonLayout[i][j] = 186;
			}
			else
			{
				BigButttonLayout[i][j] = ' ';
			}
		}
	}

	BigButttonLayout[0][0] = 254;
	BigButttonLayout[0][BigButtonHorizontalMeasure - 1] = 254;
	BigButttonLayout[BigButtonVerticleMeasure - 1][0] = 254;
	BigButttonLayout[BigButtonVerticleMeasure - 1][BigButtonHorizontalMeasure - 1] = 254;

}

void Menus::PopulateChoiceOutlineBox()
{
	for (int i = 0; i < ChoiceOutlineVerticleMeasure; i++)
	{
		for (int j = 0; j < ChoiceOutlineHorizontalMeasure; j++)
		{
			ChoiceOutlineLayout[i][j] = ' ';
		}
	}

	//Fill in for borders
	ChoiceOutlineLayout[0][0] = 201;
	ChoiceOutlineLayout[0][1] = 205;
	ChoiceOutlineLayout[1][0] = 186;

	ChoiceOutlineLayout[ChoiceOutlineVerticleMeasure - 1][0] = 200;
	ChoiceOutlineLayout[ChoiceOutlineVerticleMeasure - 2][0] = 186;
	ChoiceOutlineLayout[ChoiceOutlineVerticleMeasure - 1][1] = 205;

	ChoiceOutlineLayout[0][ChoiceOutlineHorizontalMeasure - 1] = 187;
	ChoiceOutlineLayout[0][ChoiceOutlineHorizontalMeasure - 2] = 205;
	ChoiceOutlineLayout[1][ChoiceOutlineHorizontalMeasure - 1] = 186;

	ChoiceOutlineLayout[ChoiceOutlineVerticleMeasure - 1][ChoiceOutlineHorizontalMeasure - 1] = 188;
	ChoiceOutlineLayout[ChoiceOutlineVerticleMeasure - 2][ChoiceOutlineHorizontalMeasure - 1] = 186;
	ChoiceOutlineLayout[ChoiceOutlineVerticleMeasure - 1][ChoiceOutlineHorizontalMeasure - 2] = 205;

}

Menus::~Menus()
{

}

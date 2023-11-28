#include "Menus.h"

Menus::Menus()
{
	this->PopulateBigButton();
	this->PopulateChoiceOutlineBox();
	this->PopulateCardChoiceOutlineBox();
}

Menus::Menus(std::string MenuSetupInput)
{
	this->PopulateBigButton();
	this->PopulateChoiceOutlineBox();
	this->PopulateCardChoiceOutlineBox();

	if (MenuSetupInput == "MainMenu")
	{
		this->IsMainMenu = true;
	}
	else if (MenuSetupInput == "CombatMenu")
	{
		this->IsCombatMenu = true;
	}
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

	MenuRender.DrawStringValue(FunctionalText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 8 });

	MenuRender.DrawStringValue(SelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });


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
	//Consider making this into a function to pass the 2D vector, verticle and horizontal measurements, used twice 
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

void Menus::PopulateCardChoiceOutlineBox()
{
	for (size_t i = 0; i < CardChoiceOutlineVerticleMeasure; i++)
	{
		for (size_t j = 0; j < CardChoiceOutlineHorizontalMeasure; j++)
		{
			CardChoiceOutlineLayout[i][j] = ' ';
		}
	}

	//Consider making this into a function to pass the 2D vector, verticle and horizontal measurements, used twice 
	CardChoiceOutlineLayout[0][0] = 201;
	CardChoiceOutlineLayout[0][1] = 205;
	CardChoiceOutlineLayout[1][0] = 186;

	CardChoiceOutlineLayout[CardChoiceOutlineVerticleMeasure - 1][0] = 200;
	CardChoiceOutlineLayout[CardChoiceOutlineVerticleMeasure - 2][0] = 186;
	CardChoiceOutlineLayout[CardChoiceOutlineVerticleMeasure - 1][1] = 205;

	CardChoiceOutlineLayout[0][CardChoiceOutlineHorizontalMeasure - 1] = 187;
	CardChoiceOutlineLayout[0][CardChoiceOutlineHorizontalMeasure - 2] = 205;
	CardChoiceOutlineLayout[1][CardChoiceOutlineHorizontalMeasure - 1] = 186;

	CardChoiceOutlineLayout[CardChoiceOutlineVerticleMeasure - 1][CardChoiceOutlineHorizontalMeasure - 1] = 188;
	CardChoiceOutlineLayout[CardChoiceOutlineVerticleMeasure - 2][CardChoiceOutlineHorizontalMeasure - 1] = 186;
	CardChoiceOutlineLayout[CardChoiceOutlineVerticleMeasure - 1][CardChoiceOutlineHorizontalMeasure - 2] = 205;

}

void Menus::Player1WinsMenu()
{
	Renderer PlayerWinsMenuRenderer;

	PlayerWinsMenuRenderer.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(1) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
	PlayerWinsMenuRenderer.DrawStringValue("VICTORY!!", { MenuRenderXCoord + 3, MenuRenderYCoords.at(1) + 2 });

}

void Menus::StartCombatMenu(Renderer CombatMenuRender)
{
	CombatMenuRender.DrawStringValue(CombatSelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });
}

void Menus::InitiateCombatMenu(Renderer InitiateCombatMenuRenderer)
{
	InitiateCombatMenuRenderer.DrawStringValue(InitiateCombatText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });
}

void Menus::InitiateBestiaryMenu(Renderer InitiateRendererMenu)
{
	InitiateRendererMenu.DrawStringValue(InitiateBestiaryText, { 5, 2 });
}

void Menus::PrintBestiarySelection(Renderer PrintBestiarySelection)
{
	PrintBestiarySelection.DrawCardVector(CardChoiceOutlineLayout, { 4, 6, }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
}

void Menus::GenerateVectorForBestiaryCoords(std::vector<int> XCOORDS, std::vector<int> YCOORDS)
{
	for (size_t i = 0; i < XCOORDS.size(); i++)
	{
		BestiaryXCOORDSVec.at(i) = XCOORDS.at(i) - 2;
	}
	for (size_t i = 0; i < YCOORDS.size(); i++)
	{
		BestiaryYCOORDSVec.at(i) = YCOORDS.at(i) - 1;
	}

}

void Menus::CombatMenuFirstAndLastPreview(Renderer MenuRender, std::vector<int> XCOORDS, int YCOORDS)
{
	MenuRender.DrawStringValue(PreCombatMenuText, { 1, 1 });

	//Renders the first box with the "Front" text
	MenuRender.DrawCardVector(CardChoiceOutlineLayout, { XCOORDS.at(3) - 1, YCOORDS - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	MenuRender.DrawStringValue(CombatMenuFrontText, { XCOORDS.at(3) - 1, YCOORDS + 7 });

	MenuRender.DrawCardVector(CardChoiceOutlineLayout, { XCOORDS.at(0) - 1, YCOORDS - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	MenuRender.DrawStringValue(CombatMenuBackText, { XCOORDS.at(0) - 1, YCOORDS + 7 });

}

void Menus::CombatInitiatedMenu(Renderer MenuRender, std::vector<int> P1XCOORDS, std::vector<int> P2XCOORDS, int YCOORDS, int P1TargetVecLocation, int P2TargetVecLocation)
{
	MenuRender.DrawStringValue(CombatInitializedText, { 1, 1 });

	//Draws P1 Card Target
	MenuRender.DrawCardVector(CardChoiceOutlineLayout, { P1XCOORDS.at(P1TargetVecLocation) - 1, YCOORDS - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	MenuRender.DrawStringValue(CombatMenuTargetText, { P1XCOORDS.at(P1TargetVecLocation) - 1, YCOORDS + 7 });

	MenuRender.DrawCardVector(CardChoiceOutlineLayout, { P2XCOORDS.at(P2TargetVecLocation) - 1, YCOORDS - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);
	MenuRender.DrawStringValue(CombatMenuTargetText, { P2XCOORDS.at(P2TargetVecLocation) - 1, YCOORDS + 7 });

}

void Menus::CardCatalogAndDeckBuilderMenu(Renderer CatalogRender)
{
	CatalogRender.DrawStringValue(CatalogMenuTextVec.at(0), { 1,1 });
	CatalogRender.DrawStringValue(CatalogMenuTextVec.at(1), { 57, 1 });

}

void Menus::PlayerIsViewingCardCatalogMenu(Renderer CatalogRender, std::vector<int> CatalogXCOORDS, std::vector<int> CatalogYCOORDS, int TargetXCOORDVecLocation, int TARGETYCOORDVecLocation)
{
	CatalogRender.DrawCardVector(CardChoiceOutlineLayout, { CatalogXCOORDS.at(TargetXCOORDVecLocation) - 1, CatalogYCOORDS.at(TARGETYCOORDVecLocation) - 1 }, CardChoiceOutlineVerticleMeasure, CardChoiceOutlineHorizontalMeasure);

}

void Menus::PrintMenu(Renderer MenuRender, int SelectionVariable)
{
	if (this->IsMainMenu == true)
	{
		//Must Put Overlay after the initial border object to Work
		MenuRender.DrawCardVector(ChoiceOutlineLayout, { MenuRenderXCoord - 2, MenuRenderYCoords.at(SelectionVariable) - 1 }, ChoiceOutlineVerticleMeasure, ChoiceOutlineHorizontalMeasure);
		MenuRender.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(0) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
		MenuRender.DrawStringValue(MenuButtonText.at(0), { MenuRenderXCoord + 3, MenuRenderYCoords.at(0) + 2 });

		MenuRender.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(1) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
		MenuRender.DrawStringValue(MenuButtonText.at(1), { MenuRenderXCoord + 3, MenuRenderYCoords.at(1) + 2 });

		MenuRender.DrawCardVector(BigButttonLayout, { MenuRenderXCoord, MenuRenderYCoords.at(2) }, BigButtonVerticleMeasure, BigButtonHorizontalMeasure);
		MenuRender.DrawStringValue(MenuButtonText.at(2), { MenuRenderXCoord + 3, MenuRenderYCoords.at(2) + 2 });

		MenuRender.DrawStringValue(FunctionalText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 8 });

		MenuRender.DrawStringValue(SelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });
	}
	else if (this->IsCombatMenu == true)
	{
		MenuRender.DrawStringValue(CombatSelectionText, { MenuRenderXCoord, MenuRenderYCoords.at(2) + 10 });
	}
}



void Menus::Player2WinsMenu()
{

}

Menus::~Menus()
{

}

#include "VanillaCards.h"

VanillaCards::VanillaCards()
{

}

VanillaCards::VanillaCards(int HP, int ATT, std::string NM)
{
	this->Health = HP;
	this->Attack = ATT;
	this->Name = NM;
	this->NameAbr = NM[0];
	SetupCardLayout();
}

void VanillaCards::RenderNode(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	RenderQuad.DrawCardVector(CardLayout, { XCOORD, YCOORD }, VerticleMeasure, HorizontalMeasure);
	RenderHealth(RenderQuad, XCOORD, YCOORD);
	RenderAttack(RenderQuad, XCOORD, YCOORD);
}

void VanillaCards::RenderHealth(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	RenderQuad.DrawCardIntValue(Health, { XCOORD, YCOORD });
}

void VanillaCards::RenderAttack(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	XCOORD = XCOORD + HorizontalMeasure - 1;
	RenderQuad.DrawCardIntValue(Attack, { XCOORD, YCOORD });
}

void VanillaCards::SetupCardLayout()
{
	for (size_t i = 0; i < VerticleMeasure; i++)
	{
		for (size_t j = 0; j < HorizontalMeasure; j++)
		{
			CardLayout[i][j] = ' ';

			if (i == 0 || i == VerticleMeasure - 1)
			{
				CardLayout[i][j] = 205;
			}
			else if (j == 0 || j == HorizontalMeasure - 1)
			{
				CardLayout[i][j] = 186;
			}
		}
	}
	//CardLayout[2][1] = 186;
	CardLayout[VerticleMeasure - 1][0] = 200;
	//CardLayout[6][0] = NameAbr;
	CardLayout[VerticleMeasure - 1][HorizontalMeasure - 1] = 188;
}

VanillaCards::~VanillaCards()
{
}

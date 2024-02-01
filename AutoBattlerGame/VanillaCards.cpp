#include "VanillaCards.h"
#include "CombatDataHandler.h"

VanillaCards::VanillaCards()
{

}

VanillaCards::VanillaCards(int HP, int ATT, std::string NM, std::string Type)
{
	this->Health = HP;
	this->Attack = ATT;
	this->Name = NM;
	this->CardType = Type;
	this->NameAbrFirstLetter = NM[0];
	this->NameAbrSecondLetter = NM[1];
	this->NameAbrThirdLetter = NM[2];
	this->NameAbrFourthLetter = NM[3];
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
	RenderQuad.DrawCardIntValue(Health, { XCOORD, YCOORD + 1});
}

void VanillaCards::RenderAttack(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	XCOORD = XCOORD + HorizontalMeasure - 1;
	RenderQuad.DrawCardIntValue(Attack, { XCOORD, YCOORD + 1 });
}

void VanillaCards::ReduceHP(int& EnemyATT)
{
	this->Health -= EnemyATT;
}

void VanillaCards::RoundHealthtoZero()
{
	this->Health = 0;
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
	CardLayout[0][0] = 'H';
	CardLayout[0][HorizontalMeasure - 1] = 'A';
	CardLayout[3][1] = NameAbrFirstLetter;
	CardLayout[3][2] = NameAbrSecondLetter;
	CardLayout[3][3] = NameAbrThirdLetter;
	CardLayout[3][4] = NameAbrFourthLetter;
}

void VanillaCards::PreCombatAbility(CombatDataHandler& DataHandler, std::string Owner)
{

}

VanillaCards::~VanillaCards()
{
}

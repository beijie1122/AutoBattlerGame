#include "Menus.h"

Menus::Menus()
{
	this->PopulateBigButton();
	this->PopulateChoiceOutlineBox();
	this->PopulateCardChoiceOutlineBox();
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

void Menus::PrintMenu(CombatDataHandler& DataHandler)
{

}

Menus::~Menus()
{

}

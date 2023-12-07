#pragma once
#include <string>
#include <vector>
#include "Renderer.h"

class CombatDataHandler;

class VanillaCards
{
public:

	int Health;

	int Attack;

	std::string CardType;

	std::string VanillaType = "Vanilla";

	std::string Name;
	char NameAbrFirstLetter;
	char NameAbrSecondLetter;
	char NameAbrThirdLetter;
	char NameAbrFourthLetter;

	bool IsCardBlank = false;

	bool DoesCardHavePreCombatAbility = false;

	int HorizontalMeasure = 6;

	unsigned int VerticleMeasure = 6;

	std::vector<std::vector<char>> CardLayout{ VerticleMeasure, std::vector<char>(HorizontalMeasure) };

	VanillaCards();

	VanillaCards(int HP, int ATT, std::string NM);

	void RenderNode(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void RenderHealth(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void RenderAttack(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void ReduceHP(int& EnemyATT);

	void IncreaseHP(int& GrantedHP);

	void IncreaseATT(int& GrantedATT);

	void ReduceATT(int& ReduceAmount);

	void RoundHealthtoZero();

	void SetupCardLayout();

	virtual void PreCombatAbility(CombatDataHandler& DataHandler, std::string Owner);

	~VanillaCards();
};


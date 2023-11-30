#pragma once
#include <string>
#include <vector>
#include "Renderer.h"

class VanillaCards
{
public:

	int Health;

	int Attack;

	std::string Name;
	std::string NameAbr;
	bool IsCardBlank = false;

	int HorizontalMeasure = 6;

	unsigned int VerticleMeasure = 6;

	std::vector<std::vector<char>> CardLayout{ VerticleMeasure, std::vector<char>(HorizontalMeasure) };

	VanillaCards();

	VanillaCards(int HP, int ATT, std::string NM);

	void RenderNode(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void RenderHealth(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void RenderAttack(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void SetupCardLayout();

	~VanillaCards();
};


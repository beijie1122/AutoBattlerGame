#pragma once
#include <string>
#include "Renderer.h"

class Node
{
public:

	int Health;
	int Attack;
	Node* next;
	Node* prev;
	
	std::string Name;
	char NameAbr;

	int HorizontalMeasure = 6;

	int VerticleMeasure = 6;

	std::vector<std::vector<char>> CardLayout { VerticleMeasure, std::vector<char>(HorizontalMeasure) };

	Node();

	Node(int HP, int Att, std::string NM);

	void RenderNode(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void RenderHealth(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void RenderAttack(Renderer& RenderQuad, int XCOORD, int YCOORD);

	void SetupCardLayout();


};


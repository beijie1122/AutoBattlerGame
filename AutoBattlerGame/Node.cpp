#include "Node.h"
#include <iostream>
#include <vector>


Node::Node()
{

}

Node::Node(int HP, int Att, std::string NM)
{
	this->Health = HP;
	this->Attack = Att;
	this->Name = NM;
	this->NameAbr = NM[0];
	SetupCardLayout();
	next = NULL;
}

void Node::SetupCardLayout()
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

void Node::RenderNode(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	RenderQuad.DrawCardVector(CardLayout, { XCOORD, YCOORD }, VerticleMeasure, HorizontalMeasure);
	RenderHealth(RenderQuad, XCOORD, YCOORD);
	RenderAttack(RenderQuad, XCOORD, YCOORD);
}

void Node::RenderHealth(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	RenderQuad.DrawCardIntValue(Health, { XCOORD, YCOORD });
}

void Node::RenderAttack(Renderer& RenderQuad, int XCOORD, int YCOORD)
{
	XCOORD = XCOORD + HorizontalMeasure - 1;
	RenderQuad.DrawCardIntValue(Attack, { XCOORD, YCOORD });
}



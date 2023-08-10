#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "LLNodeOperations.h"
#include "Renderer.h"

int main()
{
	InitializeRenderer();

	std::vector<int> CardHealth{ 1, 2, 5, 4};
	std::vector<int> CardAttack{ 2, 1, 1, 2 };
	std::vector<std::string> CardName{ "Guard", "Trooper", "Attacker", "Backup" };

	std::vector<int> XCoordVec{ 5, 12, 18, 24 };

	int YCoord = 5;

	Node* Player1CardCatalog = new Node();

	LLNodeOperations PerformOperationsObject;

	Player1CardCatalog = PerformOperationsObject.TakeInputFromVector(CardHealth, CardAttack, CardName);


	while (true)
	{
		Renderer RenderingObjects;

		PerformOperationsObject.print(Player1CardCatalog, RenderingObjects, XCoordVec, YCoord);


		//PerformOperationsObject.print(Player1CardCatalog, RenderingObjects);
	}

	

	return 0;
}
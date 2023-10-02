#pragma once

#include "Node.h"
#include <string>
#include <vector>
#include <iostream>
#include "Renderer.h"

class LLNodeOperations
{
public:

	std::vector<int> BestiaryXCOORD{ 5, 14, 23, 31, 40 };

	std::vector<int> BestiaryYCOORD{7, 14, 21};

	
	//Deck Builder Menu Player Deck Locations
	std::vector<int> PlayerDeckXCOORD {57, 66, 75, 84};

	int PlayerDeckYCOORD = 7;


	int BestiaryBaseHP;

	int BestiaryBaseATT;

	std::string BestiaryBaseName;

	LLNodeOperations();

	Node* TakeInputFromVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec);

	Node* SetupBestiary();

	void print(Node* head, Renderer &RenderQuad, std::vector<int> XCOORDVec, int YCOORD);

	void SortLL(Node** headref);

	Node* SortedMerge(Node* a, Node* b);

	void FrontBackSplit(Node* Source, Node** FrontRef, Node** BackRef);

	Node* CopyDataValueofLinkedList(Node* Source);

	void PrintBestiary(Node* head, Renderer& RenderBestiary);

	void PrintPlayerCatalog(Node* head, Node* PlayerDeck, Renderer& RenderCatalog);

	Node* SetupPlayerCardCatalog(Node* head, Node* PlayerDeck);

	Node* CreateBlankCard(Node* head);


	~LLNodeOperations();
};


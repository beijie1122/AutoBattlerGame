#pragma once

#include "Node.h"
#include <string>
#include <vector>
#include <iostream>
#include "Renderer.h"

class LLNodeOperations
{
public:

	LLNodeOperations();

	Node* TakeInputFromVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec);

	void print(Node* head, Renderer &RenderQuad, std::vector<int> XCOORDVec, int YCOORD);

	void SortLL(Node** headref);

	Node* SortedMerge(Node* a, Node* b);

	void FrontBackSplit(Node* Source, Node** FrontRef, Node** BackRef);

	Node* CopyDataValueofLinkedList(Node* Source);


	~LLNodeOperations();
};


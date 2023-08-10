
#include "LLNodeOperations.h"


LLNodeOperations::LLNodeOperations()
{

}

Node* LLNodeOperations::TakeInputFromVector(std::vector<int> HPVec, std::vector<int> ATTVec, std::vector<std::string> NameVec)
{
	Node* head = NULL;
	Node* tail = NULL;

	for (size_t i = 0; i < HPVec.size(); i++)
	{
		Node* n = new Node(HPVec.at(i), ATTVec.at(i), NameVec.at(i));

		std::cout << n->Name << n->Health << n->Attack << "\n";

		if (head == NULL)
		{
			head = n;
			tail = n;
			n->prev = NULL;
		}
		else
		{
			n->prev = tail;
			tail->next = n;
			tail = n;
		}

	}

	return head;

}

void LLNodeOperations::print(Node* head, Renderer& RenderQuad, std::vector<int> XCOORDVec, int YCOORD)
{
	Node* temp = head;

	while (temp != NULL)
	{
		for (size_t i = 0; i < XCOORDVec.size(); i++)
		{
			temp->RenderNode(RenderQuad, XCOORDVec.at(i), YCOORD);
			temp = temp->next; 
		}
	}
}

void LLNodeOperations::SortLL(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	if (head == NULL || head->next == NULL)
	{
		return;
	}

	FrontBackSplit(head, &a, &b);

	SortLL(&a);
	SortLL(&b);

	*headRef = SortedMerge(a, b);

}

Node* LLNodeOperations::SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	if (a == NULL)
	{
		return b;
	}

	if (b == NULL)
	{
		return a;
	}

}

void LLNodeOperations::FrontBackSplit(Node* Source, Node** FrontRef, Node** BackRef)
{

}

LLNodeOperations::~LLNodeOperations()
{

}


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

Node* LLNodeOperations::SetupBestiary()
{
	Node* head = NULL;
	Node* tail = NULL;

	for (size_t i = 0; i < 16; i++)
	{
		Node* n = new Node(BestiaryBaseHP, BestiaryBaseATT, BestiaryBaseName);

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

//ERROR - Vector subscript is out of memory range
void LLNodeOperations::PrintBestiary(Node* head, Renderer& RenderBestiary)
{
	Node* temp = head;

	int YCOORDLocation = 0;

	int XCOORDLocation = 0;


	for (size_t i = 0; i < 15; i++)
	{
		temp->RenderNode(RenderBestiary, BestiaryXCOORD.at(XCOORDLocation), BestiaryYCOORD.at(YCOORDLocation));
		temp = temp->next;
		XCOORDLocation++;
			
		
		if (XCOORDLocation == 5)
		{
			XCOORDLocation = 0;
			YCOORDLocation++;
		
			if (YCOORDLocation == 3)
			{
				YCOORDLocation = 0;
				i = 0;
				temp = head;
			}
		}
		
	}
	//XCOORDLocation = 0;
	//temp = head;



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

Node* LLNodeOperations::CopyDataValueofLinkedList(Node* Source)
{
	Node* head = NULL;
	Node* tail = NULL;

	for (size_t i = 0; i < 4; i++)
	{
		Node* n = new Node(Source->Health, Source->Attack, Source->Name);
		Source = Source->next;

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

LLNodeOperations::~LLNodeOperations()
{

}

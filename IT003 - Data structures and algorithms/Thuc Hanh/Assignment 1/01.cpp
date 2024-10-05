/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
//###INSERT CODE HERE -

struct Point
{
	double x, y, z;
	Point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) 
	{

	}
};

bool cmp(Point p1, Point p2)
{
	if (p1.x != p2.x)
		return p1.x < p2.x;
	if (p1.y != p2.y)
		return p1.y < p2.y;
	
	return p1.z < p2.z;
}

struct Node
{
	Point Data;
	Node *Next;
	Node(Point data, Node *next = NULL): Data(data), Next(next) 
	{

	}
};

Node *insertSorted(Node *Head, Point point)
{
	Node *NewNode = new Node(point);
	if (!Head || cmp(NewNode->Data, Head->Data))
	{
		NewNode->Next = Head;
		return NewNode;
	}

	else
	{
		Node *curr = Head;
		while (curr->Next && !cmp(NewNode->Data, curr->Next->Data))
			curr = curr->Next;
		NewNode->Next = curr->Next;
		curr->Next = NewNode;
	}
	return Head;
}

void printList(Node *head)
{
	Node *curr = head;
	while (curr)
	{
		cout << curr->Data.x << " " << curr->Data.y << " " << curr->Data.z << "\n";
		curr = curr->Next;
	}
}

void deleteList(Node *head)
{
	Node *current = head;
	while (current)
	{
		Node *next = current->Next;
		delete current;
		current = next;
	}
}

void run()
{
	int n;
	cin >> n;
	Node *head = nullptr;

	for (int i = 0; i < n; i++)
	{
		double x, y, z;
		cin >> x >> y >> z;
		head = insertSorted(head, Point(x, y, z));
	}

	printList(head);
	deleteList(head);
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}
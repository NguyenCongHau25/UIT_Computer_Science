/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
//###INSERT CODE HERE -
struct Diem
{
    double x, y, z;
};

struct Node
{
    Diem data;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node *CreateNode(Diem x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

void AddTail(List &l, Diem x)
{
    Node*p = CreateNode(x);
    if (p == NULL)
        return;
    if(l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail =  p;
    }
}


void PrintList(List l)
{
    Node *p = l. head;
    while (p!=NULL)
    {
        cout << p->data.x << " " << p->data.y  << " " << p->data.z << endl;
        p = p->next;
    }
}

int Compare(Diem a, Diem b)
{
    if (a.x == b.x && a.y == b.y && a.z == b.z)
        return 1;
    return 0;

}

void Search(List L1, List L2)
{
    Node *p2 = L2.head;
    Node *p1 = new Node;
    while (p2 != NULL)
    {
        int i = 0;
        int check = 0;
        p1 = L1.head;
        while(p1 !=NULL)
        {
            if(Compare(p2->data, p1->data) == 1)
                {
                    cout << i << endl;
                    check = 1;
                    break;
                }
            i++;
            p1 = p1->next;
        }
        if (check == 0)
            cout << "KHONG" << endl;
        p2 = p2->next;
    }
}

void run()
{
    List L1;
    CreateList(L1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Diem a;
        cin >> a.x >> a.y >> a.z;
        AddTail(L1, a);
    }

    List L2;
    CreateList(L2);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Diem b;
        cin >> b.x >> b.y >> b.z;
        AddTail(L2, b);
    }

    Search(L1, L2);
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}
#include <iostream>
using namespace std;

struct Diem
{
    int x, y;
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

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

Node* CreateNode(Diem x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void AddTail(List &l, Diem x)
{
    Node *p = CreateNode(x);
    if (!p)
        return;
    if (l.head == NULL )
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

int GanToaDo(Diem A)
{
    return (A.x*A.x + A.y*A.y);
}

void Sort(List &l)
{
    Node* p1 = l.head;
    while(p1 != NULL)
    {
        Node *p2 = p1->next;
        while(p2 != NULL)
        {
            if ((GanToaDo(p1->data) > GanToaDo(p2->data)))
            {
                Diem temp;
                temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
            }
            else if ((GanToaDo(p1->data) == GanToaDo(p2->data)))
            {
                if (p1->data.x > p2->data.x)
                {
                    Diem a = p1->data;
                    p1->data = p2->data;
                    p2->data = a;
                }
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

void PrintList(List &L)
{
    Node *p = L.head;
    while(p!= NULL)
    {
        cout << p->data.x << " " << p->data.y << endl;
        p = p->next;
    }
}


int main()
{
    List myList;
    CreateList(myList);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Diem a;
        cin >> a.x >> a.y;
        AddTail(myList, a);
    }

    Sort(myList);
    PrintList(myList);
    return 0;
}
#include <iostream>
using namespace std;

struct Node;
struct List;
void CreateList(List &L);
void AddHead(List &L, int x);
void AddTail(List &L, int x);
void PrintList(List L);
int Length(List L);
void Insert(List &L, Node *p, Node *q);
int DeleteHead(List &L, int &x);
void DeleteTail(List &L);
int DeleteNode(List &L, int x);
int RemoveAfterQ(List &L, Node *q, int &x);
void RemoveList(List &L);

struct Node
{
    int Data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void CreateList(List &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

Node* CreateNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->Data = x;
    p->pNext = NULL;
    return p;
}

void AddHead(List &L, int x)
{
    Node *newnode = CreateNode(x);
    if (newnode == NULL)
        return;
    if (L.pHead == NULL)
    {
        L.pHead = newnode;
        L.pTail = newnode;
    }
    else
    {
        newnode->pNext = L.pHead;
        L.pHead = newnode;
    }
}

void AddTail(List &L, int newdata)
{
    Node *newnode = CreateNode(newdata);
    if (newnode == NULL)
        return;
    if (L.pHead == NULL)
    {
        L.pHead = newnode;
        L.pTail = newnode;
    }
    else
    {
        L.pTail->pNext = newnode;
        L.pTail = newnode;
    }
}

void PrintList(List L)
{
    Node *current = L.pHead;
    while (current != NULL)
    {
        cout << current->Data << " ";
        current = current->pNext;
    }
    cout << endl;
}

Node* Search(List L, int x)
{
    Node *current = L.pHead;
    while (current != NULL && current->Data != x)
    {
        current = current->pNext;
    }
    return current;
}

int Length(List L)
{
    int count = 0;
    Node *current = L.pHead;
    while (current != NULL)
    {
        count++;
        current = current->pNext;
    }
    return count;
}

void Insert(List &L, Node *p, Node *q)
{
    if (q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if (L.pTail == q)
            L.pTail = p;
    }
    else
    {
        AddHead(L, p->Data);
    }
}

int DeleteHead(List &L, int &x)
{
    if (L.pHead != NULL)
    {
        Node *p = L.pHead;
        x = p->Data;
        L.pHead = L.pHead->pNext;
        delete p;
        
        if (L.pHead == NULL)
            L.pTail = NULL;
        return 1;
    }
    return 0;
}

void DeleteTail(List &L)
{
    if (L.pHead == NULL)
        return;

    if (L.pHead == L.pTail)
    {
        delete L.pHead;
        L.pHead = NULL;
        L.pTail = NULL;
    }
    else
    {
        Node *temp = L.pHead;
        while (temp->pNext != L.pTail)
        {
            temp = temp->pNext;
        }
        delete L.pTail;
        L.pTail = temp;
        L.pTail->pNext = NULL;
    }
}

int DeleteNode(List &L, int x)
{
    Node *p = L.pHead;
    Node *q = NULL;
    while (p != NULL && p->Data != x)
    {
        q = p;
        p = p->pNext;
    }

    if (p == NULL)
        return 0;
    if (q != NULL)
        return RemoveAfterQ(L, q, x);
    else
        return DeleteHead(L, x);
}

int RemoveAfterQ(List &L, Node *q, int &x)
{
    if (q != NULL)
    {
        Node *p = q->pNext;
        if (p != NULL)
        {
            if (p == L.pTail)
                L.pTail = q;
            q->pNext = p->pNext;
            x = p->Data;
            delete p;
            return 1;
        }
    }
    return 0;
}

void RemoveList(List &L)
{
    Node *p;
    while (L.pHead != NULL)
    {
        p = L.pHead;
        L.pHead = p->pNext;
        delete p;
    }
    L.pTail = NULL;
}

int main()
{
    List L;
    CreateList(L);

    AddHead(L, 60);
    AddHead(L, 10);
    AddTail(L, 20);
    AddHead(L, 5);
    AddTail(L, 25);
    PrintList(L);

    int deletedValue;
    DeleteHead(L, deletedValue);
    cout << "After deleting head (" << deletedValue << "): ";
    PrintList(L);

    DeleteTail(L);
    cout << "After deleting tail: ";
    PrintList(L);

    DeleteNode(L, 20);
    cout << "After deleting node with value 20: ";
    PrintList(L);

    RemoveList(L);
    cout << "After removing entire list: ";
    PrintList(L);

    return 0;
}

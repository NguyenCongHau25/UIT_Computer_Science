#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pNext;
};

typedef Node* List;

void createList(List &l)
{
    l = NULL;
}

Node* createNode(int a)
{
    Node *p= new Node;
    //check may con du bo nho khong
    if(p==NULL)
        return NULL;
    p->info = a;
    p->pNext=NULL;
    return p;
}

void AddHead(List &l, Node* p)
{
    if(l==NULL)
        l=p;
    else
    {
        p->pNext=l;
        l=p;
    }
}

void AddTail(List &l, Node *p)
{
    if (l == NULL)
    {
        l = p;
    }
    else
    {
        Node *temp = l;
        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = p;
    }
}

void AddAfter(Node *prevNode, Node *newNode)
{
    if (prevNode == NULL)
    {
        cout << "Previous node cannot be NULL." << endl;
        return;
    }

    newNode->pNext = prevNode->pNext;
    prevNode->pNext = newNode;
}

void RemoveHead(List &l)
{
    if (l == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = l;
    l = l->pNext;
    delete temp;
}

void RemoveAfter(Node *prevNode)
{
    if (prevNode == NULL || prevNode->pNext == NULL)
    {
        cout << "Previous node or its next node cannot be NULL." << endl;
        return;
    }

    Node *temp = prevNode->pNext;
    prevNode->pNext = temp->pNext;
    delete temp;
}

void RemoveTail(List &l)
{
    if (l == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (l->pNext == NULL)
    {
        delete l;
        l = NULL;
        return;
    }

    Node *temp = l;
    while (temp->pNext->pNext != NULL)
    {
        temp = temp->pNext;
    }
    delete temp->pNext;
    temp->pNext = NULL;
}

void RemoveKey(List &l, int x)
{
    if (l == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *prev = NULL;
    Node *curr = l;

    while (curr != NULL && curr->info != x)
    {
        prev = curr;
        curr = curr->pNext;
    }

    if (curr == NULL)
    {
        cout << "Node with value " << x << " not found in the list." << endl;
        return;
    }

    if (prev == NULL)
    {
        l = l->pNext;
    }
    else
    {
        prev->pNext = curr->pNext;
    }

    delete curr;
}


Node *Search(List l, int x)
{
    Node *p = l;
    while (p != NULL && p->info != x)
        p = p->pNext;
    return p;
}


int main()
{
    List myList;
    createList(myList);

    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);
    Node *node6 = createNode(6);

    AddHead(myList, node1);
    AddAfter(node1, node2);
    AddAfter(node2, node3);
    AddAfter(node3, node4);
    AddAfter(node4, node5);
    AddTail(myList, node6);

    RemoveKey(myList, 2);
    RemoveAfter(node3);

    Node *temp = myList;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->pNext;
    }
    cout << endl;

    return 0;
}
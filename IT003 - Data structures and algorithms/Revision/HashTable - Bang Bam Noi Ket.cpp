#include <iostream>
using namespace std;

struct Node
{
    int data;
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

Node* CreateNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void AddTail(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
    {
        l.head = l.tail = p;
        return;
    }
    l.tail->next = p;
    l.tail = p;
}

struct HashTable
{
    int m;
    int n;
    List *data;
};

//vòng lặp for là m không phải ht.m
void CreateHashTable(HashTable &ht, int m)
{
    ht.data = new List[m];
    if (ht.data == NULL)
        return;
    for (int i = 0; i < m ;i++)
    {
        CreateList(ht.data[i]);
    }
    ht.m = m;
    ht.n = 0;
}

int Hash(HashTable ht, int maso)
{
    return maso % ht.m;
}

void InserHashTable(HashTable &ht, int maso, double load)
{
    if (ht.n >= (int) load*ht.m)
        return;
    int index = maso%ht.m;
    AddTail(ht.data[index], maso);
    ht.n++;
}

int main()
{
    HashTable Table;
    int m, n;
    cin >> m >> n;
    double load;
    cin >> load;
    CreateHashTable(Table, m);

    for (int i = 0; i < n; i++)
    {
        int maso;
        cin >> maso;
        InserHashTable(Table, maso, load);
    }

    return 0;
}

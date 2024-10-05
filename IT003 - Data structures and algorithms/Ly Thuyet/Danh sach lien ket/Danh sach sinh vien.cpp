#include <iostream>
using namespace std;

struct SinhVien
{
    char MS[9];
    char  Hoten[40];
    double DTB;
};

struct Node
{
    SinhVien info;
    Node* pNext;
};

typedef Node* List;


void createList(List &L);
Node* createNode(SinhVien);
void addHead(List &L, Node *p);
Node* find(List, char[]);
int Delete(List&, char[]);

void createList(List &L)
{
    L = NULL;
}

Node* createNode(SinhVien A)
{
    Node *p = new Node;
    if ( p == NULL)
        return NULL;
    p -> info = A;
    p -> pNext = NULL;
    return p;
}

void addHead(List &L, Node *p)
{
    if(L == NULL)
        L = p;
    else
    {
        p ->pNext = L;
        L = p;
    }
}

Node* find(List L, char MS[])
{
    Node *p = L;
    while (p != NULL)
        {
            if (strcmp(p->info.MS, MS))
                return p;
            p = p ->pNext;

        }
    return NULL;
}

int main()
{

    return 0;
}
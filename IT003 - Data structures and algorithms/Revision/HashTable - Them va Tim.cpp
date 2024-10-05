/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

struct hashtable
{
    int m;
    int n;
    List *table;
};

Node* CreateNode(int x)
{
    Node *p = new Node;

    p->next = NULL;
    p->key = x;
    return p;
}

void CreateList(List &l)
{
    l.head = l.tail = NULL;
}

void AddTail(List &l, int x)
{
    Node *p = CreateNode(x);
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateHashTable(hashtable &ht, int m)
{
    ht.table = new List [m];
    for (int i = 0; i < m; i++)
    {
        CreateList(ht.table[i]);
    }
    ht.m = m;
    ht.n = 0;
}

int Hash(hashtable ht, int maso)
{
    return maso%ht.m;
}
//kiểu dữ liệu truyền vào load là int sẽ bị sai
int Insert(hashtable &ht, int x, float load)
{
    if(ht.n >= (int) (load*ht.m))
    {
        return 0;
    }
    int index = Hash(ht, x);
    AddTail(ht.table[index], x);
    ht.n++;
    return 1;
}


Node* Search(hashtable ht, int x, int &dem)
{
    dem = 1;
    int index = Hash(ht, x);
    Node *current = ht.table[index].head;
    while (current != NULL && current->key != x)
    {
        dem++;
        current = current->next;

    }
    return current;
}

int main()
{
    hashtable HashTable;
    int m, n;
    float load;
    cin >> m >> load >> n;

    CreateHashTable(HashTable, m);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(HashTable, x, load);
    }
    int num;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        int k;
        cin >> k;
        int dem;
        Node *p = Search(HashTable, k, dem);
        if (p == NULL)
        {
           cout << "KHONG" << '\n';
        }
        else
        {
            cout << dem << '\n';
        }
    }
    return 0;
}
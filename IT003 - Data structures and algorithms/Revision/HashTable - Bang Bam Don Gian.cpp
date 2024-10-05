#include <iostream>
using namespace std;

struct HashTable
{
    int m;
    int n;
    int *data;
};

void CreateHashTable(HashTable &ht, int m)
{
    ht.data = new int[m];
    if(ht.data == NULL)
        return;
    for(int i = 0; i < m; i++)
    {
        ht.data[i] = 0;

    }
    ht.m = m;
    ht.n = 0;
}

void InsertHashTable(HashTable &ht, int x)
{

    int key = x%ht.m;
    int check = 0;
    for(int i = 0; i < ht.m; i++)
    {
        int index = (key+i*i)%ht.m;

        if(ht.n > (int)(1*ht.m))
            exit(1);

        if(ht.data[index] == 0)
        {
            ht.data[index] = x;
            ht.n++;
            check = 1;
            break;
        }
    }
    if (check == 0)
        cout << x << " FULL" << endl;
}

void PrintHashTable(HashTable ht)
{
    for(int i = 0; i < ht.m; i++)
    {
        cout << "index " << i << " :" ;
        cout << ht.data[i] << " " << endl;
    }
}

int main()
{
    HashTable hastable;
    int m, n;
    cin >> m >> n;
    CreateHashTable(hastable,m);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertHashTable(hastable, x);
    }
    for(int i = 0; i < hastable.m; i++)
    {
        if (hastable.data[i] == 0)
            cout << i << endl;
    }
    //PrintHashTable(hastable);

    return 0;
}
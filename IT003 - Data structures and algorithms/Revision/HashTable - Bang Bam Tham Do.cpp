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
    ht.data = new int [m];
    if (ht.data == NULL)
        return;
    for (int i = 0; i < ht.m; i++)
    {
        ht.data[i] = 0;
    }
    ht.m = m;
    ht.n = 0;
}

void InsertHashTable(HashTable &ht, int x)
{
    int key = x%ht.m;
    for (int i = 0; i < ht.m; i++)
    {
        int index = (key + i*i)%ht.m;
        if(ht.n > (int)(1*ht.m))
            return;
        if (ht.data[index] == 0)
        {
            ht.data[index] = x;
            ht.n++;
            break;
        }
    }
}

int main()
{
    HashTable hashTable;
    int m, n;
    cin >> m >> n;
    CreateHashTable(hashTable,m);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertHashTable(hashTable, x);
    }
    return 0;
}
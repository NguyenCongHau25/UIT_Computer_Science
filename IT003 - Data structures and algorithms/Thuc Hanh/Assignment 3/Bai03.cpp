/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct Hashtable
{
    int M;
    int n; 
    int *table;
};

void CreateHashtable(Hashtable &, int);
void Insert(Hashtable &, int);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

int main()
{
    Hashtable hashtable;

    int m, n;
    int x;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Insert(hashtable, x);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m)
{
    ht.table = new int[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++)
    {
        ht.table[i] = 0;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        if (ht.table[i] == 0)
            cout << i << endl;
    }
}
void DeleteHashtable(Hashtable &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

void Insert(Hashtable &ht, int x)
{
    bool KiemTra = 0;
    int key = x % ht.M;

    for (int i = 0; i < ht.M; i++)
    {
        int index = ((key % ht.M) + i * i) % ht.M;

        if (ht.table[index] == 0)
        {
            ht.table[index] = x;
            ht.n++;
            KiemTra = 1;
            break;
        }
    }
    if (!KiemTra)
        cout << x << " FULL " << endl;
}
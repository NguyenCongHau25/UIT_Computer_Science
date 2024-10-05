/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -
struct node
{
    int inf;
    node *next;
};
struct List
{
    node *head, *tail;

};
node* getNode(int y)
{
    node *p=new node;
    p -> inf = y;
    p -> next = NULL;
    return p;
}
void addHead (List &L, int y)
{
    node *p=getNode(y);
    if (L.head==NULL)
        L.head=L.tail =p;
    else 
    p->next=L.head;
    L.head=p;
}
void AddTail (List &L, int b)
{
    node *p=getNode(b);
    if (L.tail == NULL)
        L.head=L.tail = p;
    else   
        L.tail -> next = p;
        L.tail = p;
    
}

void AddAfter (List &L, int d, int e)
{
    node *k = L.head;
    while(k!=NULL)
       { 
        if(k->inf == d) 
            break;
        k=k -> next;
        }
    
    if (k==NULL) 
        addHead(L,e);
    else //tìm thấy a tại node được quản lý bởi k
    {
        node *p=getNode(e);
        //SV vẽ hình để hiểu rõ cách thức làm việc
        p ->next = k->next;
        k->next = p;
        //Xử lý ngoại lệ
        if(k == L.tail)// thì sau khi thêm node mới vào sau k thì node mới trở thành node cuối mới
            L.tail =p;
    }
}

int main()

{
    List L; 
    L.head=L.tail=NULL;
    int x, y;
    int a,b,d,e;
    while (1)
    {
        cin >> x;
        if (x==3)
            break;
        if (x==0)
            {
                cin >> y;
                addHead (L,y);
            }
        else if (x==1)
        {
            cin >> b;
            AddTail (L,b);
        }
        else if (x==2)
        {
            cin >> d >> e;
            AddAfter(L,d,e);
        }

        
    }

    node *p=L.head;
    while (p!=NULL)
    {
        cout << p->inf << " ";
        p = p->next;
    }
    return 0;
}

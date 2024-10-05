/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
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
void addHead (List &L, int x)
{
    node *p=getNode(x);
    if (L.head==NULL)
        L.head=L.tail =p;
    else 
    {
    p->next=L.head;
    L.head=p;
    }
}

int main()

{
    List L; 
    L.head=L.tail=NULL;
    int x;
    int y;
    while (1)
    {
        cin >> x;
        if (x==3)
            break;
        cin >> y;
        addHead (L,y);
    }
    node *p=L.head;
    while (p!=NULL)
    {
        cout << p->inf << " ";
        p = p->next;
    }
    return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

//###INSERT CODE HERE -
/*void insert_node(SinglyLinkedList* llist, int llist_item)
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(llist_item);

		if (!llist->head) {
			llist->head = node;
		} else {
			llist->tail->next = node;
		}

		llist->tail = node;

}*/

void insert_node(SinglyLinkedList* llist, int llist_item)
{
    SinglyLinkedListNode *p = new SinglyLinkedListNode(llist_item);

    if (!llist->head )
    {
        p->next = llist->head;
        llist->head = p;
        return;
    }
    
    SinglyLinkedListNode *p1 = llist->head;
    while(p1 ->next!=nullptr && p1->next->data < llist_item)
    {
        p1 = p1 -> next;
    }
    p ->next = p1 ->next;
    p1->next = p;

}

void reverseLinkedList(SinglyLinkedList* llist)
{
    SinglyLinkedListNode* truoc = NULL;
    SinglyLinkedListNode* ht = llist->head;
    SinglyLinkedListNode* kt = NULL;

    while (ht != NULL)
    {
        kt = ht ->next;
        ht -> next = truoc;
        truoc = ht;
        ht = kt;
    }

    llist -> head = truoc;
    
}

void printLinkedList(SinglyLinkedList* llist)
{
    SinglyLinkedListNode *p = llist ->head;
    while (p)
    {
        if (p ->next == NULL)
            cout << p -> data;
        else 
            cout << p ->data <<" ";
        p = p ->next;
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}

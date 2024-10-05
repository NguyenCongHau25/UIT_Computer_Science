/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

struct SinglyLinkedList {
	SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
		this->head = nullptr;
        this->tail = nullptr;
    }

	void insert_node(int node_data);
};

void SinglyLinkedList::insert_node(int node_data)
{
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}

		this->tail = node;
}



void print_singly_linked_list(SinglyLinkedListNode* node,char sep=' ') {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
    cout << '\n';
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2)
{

//###INSERT CODE HERE -
	SinglyLinkedListNode* Node_Merged_Head = NULL;
    SinglyLinkedListNode* Tail = NULL;
    
    while (head_list1 && head_list2) 
	{
        if (head_list1 -> data < head_list2 -> data) 
		{
            if (Node_Merged_Head == NULL) 
			{
                Node_Merged_Head = head_list1;
                Tail = head_list1;
            } 
			else 
			{
                Tail -> next = head_list1;
                Tail = Tail -> next;
            }
            head_list1 = head_list1->next;
        } 
		else 
		{
            if (Node_Merged_Head == NULL) 
			{
                Node_Merged_Head = head_list2;
                Tail = head_list2;
            } 
		else 
			{
                Tail -> next = head_list2;
                Tail = Tail -> next;
            }
            head_list2 = head_list2 -> next;
        }
    }
    
    if (head_list1)
        Tail -> next = head_list1;
    if (head_list2)
        Tail -> next = head_list2;
    
    return Node_Merged_Head;

}




int main (){
    cin.tie(0); std::ios::sync_with_stdio(false);
    
    int tests;
    cin >> tests;
    
    
    
    
    for (int t = 0; t < tests; t++){
		int llist1_num, llist2_num;
		cin >> llist1_num >> llist2_num;
		
		SinglyLinkedList* llist1 = new SinglyLinkedList();
		
		
		for (int i = 0; i < llist1_num; i++){
			int llist1_item;
			cin >> llist1_item;
			
			llist1->insert_node(llist1_item);
		}
		
		SinglyLinkedList* llist2 = new SinglyLinkedList();

		
		for (int i = 0; i < llist2_num; i++){
			int llist2_item;
			cin >> llist2_item;
			
			llist2->insert_node(llist2_item);
		}
		
		SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
		
		print_singly_linked_list(llist3);
		
		free_singly_linked_list(llist3);
		
		
	}
}

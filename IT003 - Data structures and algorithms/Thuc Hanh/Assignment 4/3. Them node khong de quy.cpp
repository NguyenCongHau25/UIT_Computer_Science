/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
insert
###End banned keyword*/

#include <iostream>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
//###INSERT CODE HERE -
    if (root == NULL)
    {
        Node* Newnode = new Node(data);
        return Newnode;
    }
    Node* current = root;
    while (current)
    {
        if (current -> data == data)
            return root;
            
        if (current->data > data)
        {
            if (current->left == NULL)
            {
                current->left = new Node(data);
                break;
            }
            else
                current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = new Node(data);
                break;
            }
            else
                current = current->right;
        }
    }
    return root;
    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}
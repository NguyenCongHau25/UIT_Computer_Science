/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void preOrder(Node *root)
    {

        if (root == NULL)
            return;

        cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    Node *Insert(Node *root, int data)
    {
        if (!root)
            return new Node(data);
        else
        {
            Node *current;
            if (data <= root->data)
            {
                current = Insert(root->left, data);
                root->left = current;
            }
            else
            {
                current = Insert(root->right, data);
                root->right = current;
            }
            return root;
        }
    }



    bool isPerfectTree(Node *root, int height, int level = 0)
    {
        if (root == NULL)
            return 1;

        if (root->left ==  NULL && root->right == NULL)
            return height == level + 1;

        if (root->left == NULL || root->right == NULL)
            return 0;

        return isPerfectTree(root->left, height, level + 1) && isPerfectTree(root->right, height, level + 1);
    }    
    
    int GetHeight(Node *root)
    {
        if (root == NULL)
            return 0;
        return max(GetHeight(root->left), GetHeight(root->right)) + 1;
    }
};

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.Insert(root, data);
    }

    int height = myTree.GetHeight(root);

    if (myTree.isPerfectTree(root, height)) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
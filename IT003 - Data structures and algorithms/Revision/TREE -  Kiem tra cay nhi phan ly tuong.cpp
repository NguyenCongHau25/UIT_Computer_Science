#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left = NULL;
    Node *right = NULL;
};

typedef Node* TREE;

Node* Insert(TREE root, int x)
{
    if(!root)
    {
       Node *p = new Node;
       p->key = x;
       return p;
    }
    else
    {
        Node* current = new Node;
        if (x <= root->key)
        {
            current = Insert(root->left, x);
            root->left = current;
        }
        else
        {
            current = Insert(root -> right, x);
            root -> right = current;
        }
    }
    return root;
}

int GetHeight(TREE root)
{
    if (root == NULL)
        return 0;
    return max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

bool Check(TREE root, int height, int level = 0)
{
    if (root == NULL)
        return 0;

    if (root ->left == NULL || root ->right == NULL)
        return 0;

    if (root -> left == NULL && root->right == NULL)
        return height == level + 1;

    return Check(root->left, height, level + 1) && Check(root->right, height, level+1);
}


int main()
{
    TREE root = NULL;

    int n;

    cin >> n;

    while(n-- > 0)
    {
        int data;
        cin >> data;
        root = Insert(root, data);
    }

    int Height = GetHeight(root);

    if (Check(root, Height))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
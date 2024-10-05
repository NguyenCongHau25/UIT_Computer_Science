#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x): data(x), left(NULL), right(NULL){}
};

struct TREE
{
    Node* root;

    TREE(): root(NULL) {}

    void Insert(int x)
    {
        root = InsertNode(root, x);
    }

    Node* InsertNode(Node* root, int x)
    {
        if (root == NULL)
        {
            return new Node(x);
        }
        if (root->data < x)
            root->right = InsertNode(root->right, x);
        else
            root->left = InsertNode(root->left, x);
        return root;
    }

    int Height(Node *root)
    {
        if (root == NULL)
            return -1;
        int left = Height(root->left);
        int right = Height(root->right);

        if (left > right)
            return left + 1;
        else
        return right + 1;
    }

    void PrintHeight()
    {
        cout << Height(root);
    }

    void NLR(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }

    void PrintList()
    {
        NLR(root);
    }

};

int main()
{
    TREE root;
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        int x;
        cin >> x;
        root.Insert(x);
    }

    root.PrintHeight();
    return 0;

}

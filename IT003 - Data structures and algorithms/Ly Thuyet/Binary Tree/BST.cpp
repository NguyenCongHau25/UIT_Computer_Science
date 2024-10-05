#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> danhsach;

struct TNODE {
    int data;
    TNODE* left;
    TNODE* right;
};

typedef struct TNODE* TREE;

TREE createTNode(int x) {
    TREE newTree = new TNODE;
    if (newTree == NULL) {
        exit(1);
    }
    newTree->data = x;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

void indanhsach() {
    for (int i : danhsach) {
        cout << i << " ";
    }
}

int insertDQ(TREE &t, int x) {
    TREE newTree = createTNode(x);
    if (t) {
        if (x == t->data) return 0;
        if (x < t->data) return insertDQ(t->left, x);
        return insertDQ(t->right, x);
    }
    t = newTree;
    return 1;
}

int insertKDQ(TREE &t, int x) {
    TREE newTree = createTNode(x);
    if (t == NULL) t = newTree;
    TREE tmp = t;
    while (tmp) {
        if (x == tmp->data) return 0;
        if (x < tmp->data) {
            if (tmp->left == NULL) tmp->left = newTree;
            else tmp = tmp->left;
        }
        else if (x > tmp->data) {
            if (tmp->right == NULL) tmp->right = newTree;
            else  tmp = tmp->right;
        }
    }
    return 1;
}

void NLR(TREE t) {
    if (t) {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

void NRL(TREE t) {
    if (t) {
        cout << t->data << " ";
        NRL(t->right);
        NRL(t->left);
    }
}

void LNR(TREE t) {
    if (t) {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}

void RNL(TREE t) {
    if (t) {
        RNL(t->right);
        cout << t->data << " ";
        RNL(t->left);
    }
}

void LRN(TREE t) {
    if (t) {
        LRN(t->left);
        LRN(t->right);
        cout << t->data << " ";
    }
}

void RLN(TREE t) {
    if (t) {
        RLN(t->right);
        RLN(t->left);
        cout << t->data << " ";
    }
}

TREE searchTNodeDQ(TREE t, int x) {
    if (t) {
        if (x == t->data) return t;
        if (x < t->data) return searchTNodeDQ(t->left, x);
        else if (x > t->data)  return searchTNodeDQ(t->right, x);
    }
    return NULL;
}

TREE searchTNodeKDQ(TREE t, int x) {
    TREE tmp = t;
    while (tmp) {
        if (x == tmp->data) return tmp; 
        if (x < tmp->data) tmp = tmp->left;
        else if (x > tmp->data) tmp = tmp->right;
    }
    return NULL;
}

void theMang(TREE &tmp, TREE &y) {
    if (y->left != NULL) {
        theMang(tmp, y->left);
    } else {
        tmp->data = y->data;
        tmp = y;
        y = y->right;
    }
}

int deleteTNode(TREE &t, int x) {
    if (t != NULL) {
        if (t->data < x) deleteTNode(t->right, x);
        else {
            if (t->data > x) deleteTNode(t->left, x);
            else {
                TREE tmp = t;
                if (t->left == NULL) t = t->right;
                else {
                    if (t->right == NULL) t = t->left;
                    else theMang(tmp, t->right);
                }
                delete tmp;
                return 1;
            }
        }
    }
    return 0;
}

int Height(TREE t) {
    if (!t) return -1;
    int a = Height(t->left);
    int b = Height(t->right);
    return (a > b ? a : b) + 1;
}

int countTNode(TREE t) {
    if (!t) return 0;
    int a = countTNode(t->left);
    int b = countTNode(t->right);
    return a + b + 1;
}

int countLeavesTNode(TREE t) {
    if (!t) return 0;
    if (t->left == NULL && t->right == NULL) return 1;
    int a = countLeavesTNode(t->left);
    int b = countLeavesTNode(t->right);
    return a + b;
}

int countOnlyChildTNode(TREE t) {
    if (!t) return 0;
    int count = 0;
    if ((t->left == NULL && t->right != NULL)
        || (t->left != NULL && t->right == NULL)) count =  1;
    int a = countOnlyChildTNode(t->left);
    int b = countOnlyChildTNode(t->right);
    return count + a + b;
}

int countTwoChildTNode(TREE t) {
    if (!t) return 0;
    int count = 0;
    if (t->left != NULL && t->right != NULL) count = 1;
    int a = countTwoChildTNode(t->left);
    int b = countTwoChildTNode(t->right);
    return count + a + b;
}

int sumOfTNode(TREE t) {
    if (!t) return 0;
    int tong = 0;
    tong = t->data;
    int a = sumOfTNode(t->left);
    int b = sumOfTNode(t->right);
    return tong + a + b;
}

void printTree(TREE root, int space, int height) {
    if (root == NULL) return;

    space += height;

    printTree(root->right, space, height);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    printTree(root->left, space, height);
}

void printBST(TREE root) {
    int height = Height(root);
    printTree(root, 0, height * 3);
}

int main() {
    TREE tree = NULL;
    string lc;
    while (1) {
        cout << "---------menu-----------\n";
        cout << "1. insert co DQ\n";
        cout << "2. insert khong DQ\n";
        cout << "3. search node co DQ\n";
        cout << "4. search node khong DQ\n";
        cout << "5. delete\n";
        cout << "6. chieu cao\n";
        cout << "7. so luong node\n";
        cout << "8. so node la\n";
        cout << "9. so node chi co mot con\n";
        cout << "10. so node co day du ca hai con\n";
        cout << "11. tong gia tri cac node\n";
        cout << "12. thoat\n";
        cout << "khac: nhap lai\n";
        cout << "------------------------\n";
        indanhsach();
        cout << endl;
        cout << "------------------------\n";
        printBST(tree);
        cout << "------------------------\n";
        cout << "NLR: "; NLR(tree);
        cout << endl;
        cout << "NRL: "; NRL(tree);
        cout << endl;
        cout << "LNR: "; LNR(tree);
        cout << endl;
        cout << "RNL: "; RNL(tree);
        cout << endl;
        cout << "LRN: "; LRN(tree);
        cout << endl;
        cout << "RLN: "; RLN(tree);
        cout << endl;
        cout << "------------------------\n";
        cout << "lua chon: ";
        cin >> lc;

        if (lc == "1") {
            int x;
            cout << "nhap so can them vao: "; cin >> x;
            danhsach.push_back(x);
            system("cls");

            if (insertDQ(tree, x)) {
                cout << "da them " << x << endl;
            }
            else {
                cout << "khong the them " << x << endl;
            }
        } else if (lc == "2") {
            int x;
            cout << "nhap so can them vao: "; cin >> x;
            danhsach.push_back(x);
            system("cls");

            if (insertKDQ(tree, x)) {
                cout << "da them " << x << endl;
            }
            else {
                cout << "khong the them " << x << endl;
            }
        } else if (lc == "3") {
            int x;
            cout << "nhap so can tim: "; cin >> x;
            system("cls");

            if (searchTNodeDQ(tree, x)) {
                cout << x << " co ton tai\n";
            } else {
                cout << x << " khong ton tai\n";
            }
        } else if (lc == "4") {
            int x;
            cout << "nhap so can tim: "; cin >> x;
            system("cls");

            if (searchTNodeKDQ(tree, x)) {
                cout << x << " co ton tai\n";
            } else {
                cout << x << " khong ton tai\n";
            }
        } else if (lc == "5") {
            int x;
            cout << "nhap so can xoa: "; cin >> x;
            system("cls");

            if (deleteTNode(tree, x)) {
                cout << "da xoa " << x << endl;
            }
            else {
                cout << "khong the xoa " << x << endl;
            }
        } else if (lc == "6") {
            system("cls");

            cout << "chieu cao cua cay: " << Height(tree);
            cout << endl;
        } else if (lc == "7") {
            system("cls");

            cout << "so luong node trong cay: " << countTNode(tree);
            cout << endl;
        } else if (lc == "8") {
            system("cls");

            cout << "so luong node la trong cay: " << countLeavesTNode(tree);
            cout << endl;
        } else if (lc == "9") {
            system("cls");

            countOnlyChildTNode(tree);
            cout << endl;
        }
        else if (lc == "10") {
            system("cls");

            cout << "so luong node co day du hai con trong cay: " << countTwoChildTNode(tree);
            cout << endl;
        }
        else if (lc == "11") {
            system("cls");

            cout << "tong gia tri cac node trong cay: " << sumOfTNode(tree);
            cout << endl;
        }
        else if (lc == "12") {
            system("cls");

            break;
        } 
        else {
            system("cls");

            continue;
        }
    }

    return 0;
}

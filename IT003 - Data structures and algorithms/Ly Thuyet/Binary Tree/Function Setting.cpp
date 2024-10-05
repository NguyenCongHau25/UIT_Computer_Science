struct TNODE
{
  int key;
  TNODE *pLeft;
  TNODE *pRight;
};

typedef TNODE *TREE;

TNODE *searchNode(TREE T, int x)
{
  if (T != NULL)
  {
    if (T->key == x)
      return T;
    if (T->key > x)
      return search(T->pLeft, x);
    return search(T->pRight, x);
  }
  return NULL;
}

void CreateTree(TREE &T)
{
  T = NULL;
}

TNODE *CreateTNode(int x)
{
  TNODE *p;
  p = new TNODE; // cấp phát vùng nhớ động
  if (p == NULL)
    exit(1);  // thoát
  p->key = x; // gán trường dữ liệu của node = x
  p->pLeft = NULL;
  p->pRight = NULL;
  return p;
}

int Insert(TREE &T, int x)
{
  if (T)
  {
    if (T->key == x)
      return 0;
    if (T->key > x)
      return Insert(T->pLeft, x);
    return Insert(T->pRight, x);
  }
  T = CreateTNode(x);
  return 1;
}

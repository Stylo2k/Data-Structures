#include "tree.h"

Tree emptyTree()
{
  return NULL;
}

Tree newTree(int n, Tree tL, Tree tR)
{
  Tree new = malloc(sizeof(struct TreeNode));
  assert(new != NULL);
  new->item = n;
  new->leftChild = tL;
  new->rightChild = tR;
  return new;
}

Tree makeTreeRec(int p, int size)
{

  int item = -1;
  if (!scanf("%d", &item))
  {
    printf("input not scanned correctly\n");
  }

  if (p > size || item == -1)
  {
    return NULL;
  }

  return newTree(item, makeTreeRec(p * 2, size),
                 makeTreeRec(p * 2 + 1, size));
}

Tree makeTree(int size)
{
  return makeTreeRec(1, size);
}

void freeTree(Tree t)
{
  if (t == NULL)
  {
    return;
  }
  freeTree(t->leftChild);  // left
  freeTree(t->rightChild); // right
  free(t);                 // empty
}

/*Visit Left Right*/
void preOrderArray(int *ar, int n, int p)
{
  if (p < n && ar[p] != -1)
  { /*position less than size and there is a node*/
    visit(ar[p]);
    preOrderArray(ar, n, 2 * p);     /*2*p meaning left child*/
    preOrderArray(ar, n, 2 * p + 1); /* 2*p+1 meaning right child*/
  }
}
/*Left Right Visit*/
void postOrderArray(int *ar, int n, int p)
{
  if (p < n && ar[p] != -1)
  {                                   /*position less than size and there is a node*/
    postOrderArray(ar, n, 2 * p);     /*2*p meaning left child*/
    postOrderArray(ar, n, 2 * p + 1); /* 2*p+1 meaning right child*/
    visit(ar[p]);
  }
}
/*Left Visit Right*/
void inOrderArray(int *ar, int n, int p)
{
  if (p < n && ar[p] != -1)
  {                             /*position less than size and there is a node*/
    inOrderArray(ar, n, 2 * p); /*2*p meaning left child*/
    visit(ar[p]);
    inOrderArray(ar, n, 2 * p + 1); /* 2*p+1 meaning right child*/
  }
}

void visit(int item)
{
  if (item != -1)
  {
    printf("%d ", item);
  }
}
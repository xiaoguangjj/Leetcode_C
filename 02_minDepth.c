#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

typedef char TElemType;

typedef struct TreeNode{
  TElemType data;
  struct TNode *lchild;
  struct TNode *rchild;
}TNode,*BinTree;

// 创建二叉树
int CreateBinTree(TNode * T)
{
  TElemType ch;
  scanf("%c",&ch);
  if (ch == '#'){
    T = NULL;
  }else{
    T = (TNode *)malloc(sizeof(TNode));
    T->data = ch;
    CreateBinTree(T->lchild); // 创建左子树
    CreateBinTree(T->rchild); //创建右子树
  }
  return 0;
}

// 深度遍历
int minDepth(TNode * root){
  if (root == NULL){
    return 0;
  }
  if (root->lchild == NULL && root->rchild == NULL){
    return 1;
  }
  int min_depth = INT_MAX;
  if (root->lchild != NULL){
    min_depth = fmin(minDepth(root->lchild), min_depth);
  }
  if (root->rchild != NULL){
    min_depth = fmin(minDepth(root->rchild), min_depth);
  }
  return min_depth + 1;
}

int main()
{
  BinTree a;
  CreateBinTree(a);
  printf("%d\n",minDepth(a));
  return 0;
}

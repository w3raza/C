#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int value;
    struct tnode * left;
    struct tnode * right;
    struct tnode * parent;
}tnode;

tnode *CreateLeaf(int wartosc,tnode *root);
void AddLeaf(int wartosc, tnode **root,tnode *dummy);

void showPreorder(tnode *element);
void showPostorder(tnode *element);

int min(tnode *root);
int max(tnode *root);

tnode *SearchIterate(tnode *parent, int wartosc);
tnode *SearchRecursive(tnode *parent, int wartosc);

tnode *Successor(tnode *x);
tnode *Predecessor(tnode *x);

void Left_Rotate(tnode **root, tnode *x);

void freeTree(tnode *root);

#endif 
/**
 * @file tree.h
 * @author Mohammad Al Shakoush (mo.alshakoush@gmail.com)
 * @brief header file for tree
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct TreeNode *Tree;

/**
 * @brief tree. Item and left and right children
 *
 */
struct TreeNode
{
  int item;
  Tree leftChild, rightChild;
};

Tree emptyTree();
Tree newTree(int n, Tree tL, Tree tR);
Tree makeTree(int size);
void preOrderArray(int *ar, int n, int p);
void postOrderArray(int *ar, int n, int p);
void inOrderArray(int *ar, int n, int p);
void visit(int item);
void freeTree(Tree t);

#endif
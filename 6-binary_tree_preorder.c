#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_preorder - goes through a binay tree
 * using pre-order traversal
 *
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointe rot a function to call for each node
 * Return: Always nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}

#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: a pointer to the root node of the tree to delete
 * Return: Always nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->left)
	{
		binary_tree_delete(tree->left);
		tree->left = NULL;
	}
	if (tree->right)
	{
		binary_tree_delete(tree->right);
		tree->right = NULL;
	}

	free(tree);
}

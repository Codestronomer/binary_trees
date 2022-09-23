#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp1;

	if (tree == NULL)
		return (NULL);

	temp1 = tree;
	tree = temp1->right;
	temp1->parent = tree;
	temp1->right = tree->left;
	tree->left = temp1;

	return (tree);
}

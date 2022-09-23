#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp1;

	if (tree == NULL)
		return (NULL);

	temp1 = tree;
	tree = temp1->left;
	temp1->parent = tree;
	temp1->left = tree->right;
	tree->right = temp1;

	return (tree);
}

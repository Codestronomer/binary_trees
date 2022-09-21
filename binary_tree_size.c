#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t heigt = 0;

	if (tree == NULL)
		return (0);
	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right);
}

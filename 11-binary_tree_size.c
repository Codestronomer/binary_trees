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
	if (tree == NULL)
		return (0);
	return (get_size(tree) / 2);
}

/**
 * get_size - helper to get the size of the node
 *
 * @tree: pointer to the node to be measured
 * Return: twice the size of the node
 */
size_t get_size(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);
	left = get_size(tree->left) + 1;
	right = get_size(tree->right) + 1;

	return (left + right);
}

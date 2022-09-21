#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_binary_tree_height - returns the height of the binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height of the binary tree minus the root node or 0
 */
size_t get_binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t rightHeight = 0;

	if (tree == NULL)
		return (0);

	leftHeight = get_binary_tree_height(tree->left);
	rightHeight = get_binary_tree_height(tree->right);

	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	return (rightHeight + 1);
}


/**
 * binary_tree_height - calls get_binary_tree_height to get height
 * of a binary tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: height of the tree or 0 if tree is NULL;
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_binary_tree_height(tree) - 1);
}

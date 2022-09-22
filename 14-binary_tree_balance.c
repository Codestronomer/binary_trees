#include "binary_trees.h"
#include <stdlib.h>


/**
 * recursive_height - get the balance factor of a binary tree
 *
 * @tree: a pointer to the node in the tree to measure
 * Return: the balance factor of the tree, or 0 if tree is NULL
 */
int recursive_height(const binary_tree_t *tree)
{

	int lHeight = 0;
	int rHeight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		lHeight = recursive_height(tree->left) + 1;
	else
		lHeight = 0;
	if (tree->right)
		rHeight = recursive_height(tree->right) + 1;
	else
		rHeight = 0;

	if (lHeight > rHeight)
		return (lHeight);
	return (rHeight);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the
 * balance factor
 * Return: the balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		lheight = recursive_height(tree->left);
	else
		lheight = -1;

	if (tree->right != NULL)
		rheight = recursive_height(tree->right);
	else
		rheight = -1;

	return (lheight - rheight);
}

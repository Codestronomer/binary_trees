#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_is_leaf - checks if a node is a leaf
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && (node->left == NULL) && (node->right == NULL))
		return (1);
	return (0);
}


/**
 * check_parents - checks if a node is lower/greater than grandparents
 *
 * @node: a pointer to the node to check
 * Return: 1 if node is valid BST, 0 otherwise
 */
int check_parents(const binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;

	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (1);

	parent = node->parent;
	grandparent = node->parent->parent;

	while (parent && grandparent)
	{
		if (parent->n < grandparent->n && node->n >= grandparent->n)
			return (0);
		if (parent->n > grandparent->n && node->n <= grandparent->n)
			return (0);

		parent = parent->parent;
		grandparent = parent->parent;
	}
	return (1);
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a Valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/* checks for leaf node */
	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left && tree->n <= tree->left->n)
		return (0);
	if (tree->right && tree->n >= tree->right->n)
		return (0);

	if ((check_parents(tree->left) == 0) ||
			(check_parents(tree->right) == 0))
		return (0);

	return (binary_tree_is_bst(tree->left) &&
	binary_tree_is_bst(tree->right));
}

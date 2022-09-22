#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: a pointer to the node to find the sibling
 * Return: a pointer to the sibling node, or NULL on failure
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	parent = node->parent;
	if (parent->left && parent->left != node)
		return (parent->left);
	if (parent->right && parent->right != node)
		return (parent->right);
	return (NULL);
}

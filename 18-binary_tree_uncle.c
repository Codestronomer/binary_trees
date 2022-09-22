#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: a pointer to the node to find the uncle
 * Return: pointer to the uncle node, NULL on failure
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;

	if (parent != NULL && grandparent != NULL)
	{
		if (grandparent->left && grandparent->left != parent)
			return (grandparent->left);
		if (grandparent->right && grandparent->right != parent)
			return (grandparent->right);
		return (NULL);
	}
	return (NULL);
}

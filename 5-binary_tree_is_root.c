#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_root - checks if a given node is a root
 *
 * @node: a pointer to the node to check
 * Return: returns 1 if node is a node, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && !(node->parent))
	{
		return (1);
	}
	return (0);
}

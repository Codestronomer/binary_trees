#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_nodes - counts the nodes with atleast 1 child
 * in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number
 * of nodes
 * Return: the number of nodes with atleast 1 child, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (binary_tree_nodes(tree->left) +
		      binary_tree_nodes(tree->right) + 1);
}

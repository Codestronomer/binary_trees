#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * get_binary_tree_depth - helper function to measure the depth 
 * of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth
 * Return: depth of the Node, if tree is NULL, return 0
 */
size_t get_binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree == NULL)
		return (0);

	node_depth = get_binary_tree_depth(tree->parent);

	return (node_depth + 1);
}


/**
 * binary_tree_depth - measures the depth of a binary tree
 *
 * @tree: pointer to the node to be measured
 * Return: depth of the Node minus - 1 or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (get_binary_tree_depth(tree) - 1);
}

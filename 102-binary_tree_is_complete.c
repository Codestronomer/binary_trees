#include "binary_trees.h"
#include <stdlib.h>


/**
 * countNodes - counts the number of nodes in a binary tree
 *
 * @root: pointer to the root node of the tree
 * Return: number of nodes
 */
unsigned int countNodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}


/**
 * is_complete - checks if the binary tree is complete or not
 *
 * @root: pointer to the root node of the tree
 * @index: current index of node
 * @n_nodes: number of nodes
 * Return: 1 if tree is complete, 0 if not
 */
int is_complete(const binary_tree_t *root, unsigned int index,
		unsigned int n_nodes)
{
	/* An empty tree is complete */
	if (root == NULL)
		return (1);

	/* if Index assigned to current node is more than */
	/* number of nodes in tree, then tree is not complete */
	if (index >= n_nodes)
		return (0);

	/* Recur for left and right subtrees */
	return (is_complete(root->left, 2 * index + 1, n_nodes) &&
			is_complete(root->right, 2 * index + 2, n_nodes));
}

/**
 * int binary_tree_is_complete - checks if binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 on Failure
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned int n_nodes;

	if (tree == NULL)
		return (0);

	n_nodes = countNodes(tree);

	return (is_complete(tree, 0, n_nodes));
}

#include "binary_trees.h"


/**
 * tree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the node to measure its height
 * Return: height or 0 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree != NULL)
		return (-1);

	lheight = tree_height(tree->left);
	rheight = tree_height(tree->right);

	if (lheight > rheight)
		return (lheight + 1);
	return (rheight + 1);
}

/**
 * is_leaf - checks if a node is a leaf
 *
 * @node: node to check
 * Return: 1 if true, 0 if false
 */
int is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree perfect and 0 if it isn't or NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_leaf(tree->left) && is_leaf(tree->right))
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		if (tree_height(tree->left) == tree_height(tree->right))
			if (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right))
				return (1);
	return (0);
}

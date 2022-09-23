#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_binary_tree_height - measure the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to traverse
 * Return: height of the tree
 */
size_t get_binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight = 0;
	size_t rheight = 0;

	if (tree == NULL)
		return (0);

	lheight = get_binary_tree_height(tree->left);
	rheight = get_binary_tree_height(tree->right);

	if (lheight > rheight)
		return (lheight + 1);
	return (rheight + 1);
}

/**
 * print_current_level - prints the nodes in the current level
 *
 * @tree: a pointer to the tree
 * @level: current level of the nodes to print
 * @func: pointer to the print function
 */
void print_current_level(const binary_tree_t *tree, int level,
		void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
}


/**
 * binary_tree_levelorder - goes through tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: Always Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree != NULL || func != NULL)
	{
		height = get_binary_tree_height(tree);

		for (i = 1; i <= height; i++)
			print_current_level(tree, i, func);
	}
}

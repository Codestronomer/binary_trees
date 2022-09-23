#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_search - searches for a value in a binary search tree
 *
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
        if (tree == NULL)
                return ((bst_t *)tree);

        if (tree->n > value)
		return (bst_search(tree->left, value));

	if (tree->n < value)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}

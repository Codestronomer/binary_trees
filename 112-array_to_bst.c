#include "binary_trees.h"
#include <stdlib.h>


/**
 * array_to_bst - builds a binary search tree from an array
 *
 * @array: a pointe to the first element of the array to be converted
 * @size: is the number of elements  in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	if (i == size)
		return (root);
	return (NULL);
}

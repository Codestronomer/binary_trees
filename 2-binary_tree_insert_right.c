#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right child
 * of another node
 *
 * @parent: a pointer to the node to insert the right child in
 * @value: value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	binary_tree_t *temp;

	if (parent != NULL)
	{
		new = malloc(sizeof(binary_tree_t));
		if (new == NULL)
			return (NULL);

		new->n = value;
		new->parent = parent;
		new->right = NULL;
		if (parent->right == NULL)
			parent->right = new;
		else
		{
			temp = parent->right;
			parent->right = new;
			temp->parent = new;
			new->right = temp;
		}

		return (new);
	}
	return (NULL);
}

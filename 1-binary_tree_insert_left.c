#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_insert_left - inserts a node as the left child
 * of another node
 *
 * @parent: a pointer to the node to insert the left child in
 * @value: value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL)

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	if (parent->left == NULL)
		parent->left = new;
	else
	{
		temp = parent->left;
		parent->left = new;
		temp->parent = new;
		new->left = temp;
	}
	return (new);
}

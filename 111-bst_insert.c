#include "binary_trees.h"
#include <stdlib.h>


/**
 * add_node_bst - inserts a node to a binary search tree
 *
 * @tree: tree where node would be added to binary tree
 * @value: to be added to the tree
 * Return: pointer to the added node, or NULL on failure
 */
bst_t *add_node_bst(bst_t **tree, int value)
{
	bst_t *temp = (*tree);
	bst_t *parent = NULL;
	bst_t *new = malloc(sizeof(bst_t));

	if (new != NULL)
	{
		new->n = value;
		while (1)
		{
			parent = temp;
			if (parent->n < value)
			{
				temp = temp->right;
				if (temp == NULL)
				{
					parent->right = new;
					new->parent = parent;
					return (new);
				}
			}
			else if (parent->n > value)
			{
				temp = temp->left;
				if (temp == NULL)
				{
					parent->left = new;
					new->parent = parent;
					return (new);
				}
			}
			else
			{
				/* ignore cause node is equal to the value */
				return (NULL);
			}
		}
	}
	return (NULL);
}


/**
 * bst_insert - inserts a value in a binary search tree
 *
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if ((*tree) == NULL)
	{
		(*tree) = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (add_node_bst(tree, value));
}
